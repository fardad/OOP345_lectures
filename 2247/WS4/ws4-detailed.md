## Detailed Implementation Guide for Workshop 4

#### **Milestone 1: Station Class**
The `Station` class represents an inventory station with attributes like item details, serial numbers, and quantity.

**Attributes:**
- `m_id`: A unique ID for each station, automatically assigned.
- `m_itemName`: The name of the item managed by the station.
- `m_description`: A short description of the item.
- `m_serialNumber`: The serial number assigned to the next item.
- `m_quantity`: The number of items currently available.
- `field_width` and `id_generator`: Static members for formatting and ID generation.

**Member Functions:**
1. **Constructor (`Station(const std::string& record)`)**  
   - Parse a formatted input string to initialize the station's attributes.
   - Use the `Utilities` class to extract tokens and handle delimiters.

2. **`const std::string& getItemName() const`**  
   - Return the name of the item handled by the station.

3. **`size_t getNextSerialNumber()`**  
   - Return the current serial number and increment it for the next item.

4. **`size_t getQuantity() const`**  
   - Return the current quantity of items in stock.

5. **`void updateQuantity()`**  
   - Reduce the quantity by one if items are still available.

6. **`void display(std::ostream&, bool full) const`**  
   - If `full` is true, display all details: ID, name, serial number, quantity, and description.
   - If `full` is false, display only the ID, name, and serial number.

---

#### **Milestone 2: CustomerOrder Class**
The `CustomerOrder` class models an order with multiple items requested by a customer.

**Attributes:**
- `m_name`: Customer's name.
- `m_product`: Name of the product being ordered.
- `m_lstItem`: A dynamically allocated array of pointers to `Item` structures.
- `m_cntItem`: The number of items in the order.
- `m_widthField`: A static member for formatting output.

**Member Functions:**
1. **Constructor (`CustomerOrder(const std::string& record)`)**  
   - Parse a formatted string to initialize the customer's name, product, and item list.
   - Use the `Utilities` class to extract tokens.
   - Dynamically allocate memory for the item list.

2. **Destructor (`~CustomerOrder()`)**  
   - Deallocate all dynamically allocated memory.

3. **Copy Constructor and Copy Assignment**  
   - **Deleted**. Copying a `CustomerOrder` should not be allowed to avoid shallow copies.

4. **Move Constructor and Move Assignment**  
   - Transfer ownership of resources from the source object to the current object.
   - Set the source object’s pointers to `nullptr` to avoid double deletions.

5. **`bool isOrderFilled() const`**  
   - Return `true` if all items in the order are filled, `false` otherwise.

6. **`bool isItemFilled(const std::string& itemName) const`**  
   - Check if the specified item is filled. Return `true` if it is, `false` otherwise.

7. **`void fillItem(Station& station, std::ostream& os)`**  
   - Search for an item in the order that matches the station's item name.
   - If the item is found and the station has stock:
     - Mark the item as filled.
     - Assign a serial number from the station.
     - Decrement the station's quantity.
   - If the station is out of stock, log the failure to `os`.

8. **`void display(std::ostream&) const`**  
   - Display customer and product details.
   - For each item, display its name, serial number, and whether it is filled.

---

#### **Milestone 3: Workstation and LineManager Classes**

##### **Workstation Class**
The `Workstation` class extends the `Station` class and manages a queue of customer orders.

**Attributes:**
- `m_orders`: A queue of orders currently being processed at the station.
- `m_pNextStation`: A pointer to the next station in the line.

**Member Functions:**
1. **Constructor (`Workstation(const std::string& record)`)**  
   - Initialize the station by passing the record to the `Station` constructor.

2. **`void fill(std::ostream& os)`**  
   - Call the `fillItem` function on the front order in the queue using this station.

3. **`bool attemptToMoveOrder()`**  
   - If the front order’s required item is filled or out of stock:
     - Pass it to the next station or move it to `g_completed` or `g_incomplete` based on its status.
   - Remove the order from the queue.

4. **`void setNextStation(Workstation* station)`**  
   - Set the next station in the line.

5. **`Workstation* getNextStation() const`**  
   - Return a pointer to the next station.

6. **`void display(std::ostream&) const`**  
   - Display the current station’s name and its next station (or "End of Line").

7. **`Workstation& operator+=(CustomerOrder&& order)`**  
   - Add a new order to the back of the queue.

---

##### **LineManager Class**
The `LineManager` class coordinates the entire assembly line.

**Attributes:**
- `activeLine`: A vector of pointers to all `Workstation` objects in the line.
- `m_firstStation`: Pointer to the first station in the sequence.
- `m_cntCustomerOrder`: The total number of customer orders.

**Member Functions:**
1. **Constructor (`LineManager(const std::string&, const std::vector<Workstation*>&)`)**  
   - Parse a configuration file to set up the assembly line and station connections.
   - Identify the first station.

2. **`void reorderStations()`**  
   - Arrange the `Workstation` objects in the order they appear on the line.

3. **`bool run(std::ostream&)`**  
   - Perform one iteration of the assembly line:
     - Move the first order in `g_pending` to the first station.
     - Call `fill` and `attemptToMoveOrder` on each station.
   - Return `true` when all orders are processed.

4. **`void display(std::ostream&) const`**  
   - Display the current sequence of stations.

---

### General Tips for Implementation
- **File Parsing**: Use the `Utilities` class to handle delimiters and extract tokens from input files.
- **Memory Management**: Ensure proper cleanup of dynamically allocated memory using destructors and the Rule of Five.
- **Exception Safety**: Handle edge cases like empty input, missing tokens, and invalid file paths.
- **Testing**: Use the provided test files to validate each class incrementally.
