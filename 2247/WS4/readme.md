# Workshop 4: Assembly Line Simulation

**Objective**  
Build a simulation of an assembly line for processing customer orders. You will implement multiple interconnected classes (`Station`, `CustomerOrder`, `Workstation`, `LineManager`) to manage the flow of orders through the system. This workshop emphasizes dynamic memory management, object relationships, and exception handling.

---

### Milestones

#### Milestone 1: **Station Class**
- Represents an inventory station that processes specific items.
- **Attributes**:
  - Station ID, item name, item description, current serial number, and remaining quantity.
- **Tasks**:
  1. Parse a single line from a text file to initialize the station.
  2. Provide member functions to:
     - Retrieve the next serial number and update it.
     - Decrement the quantity of items.
     - Display station information (summary or detailed).

---

#### Milestone 2: **CustomerOrder Class**
- Represents a customer order with requested items.
- **Attributes**:
  - Customer name, product name, a list of requested items, and the total number of items.
- **Tasks**:
  1. Parse a single line from a text file to initialize a customer order.
  2. Implement:
     - A function to check if an order or a specific item is filled.
     - A function to fill an item at a station if available.
     - A display function for the order and its items.
  3. Implement the **Rule of Five** to manage dynamic memory safely.

---

#### Milestone 3: **Workstation and LineManager Classes**
- **`Workstation` Class**:
  - A station that processes customer orders and passes them to the next station in the line.
  - **Tasks**:
    1. Manage a queue of orders being processed.
    2. Attempt to fill the front order using available inventory.
    3. Pass filled or incomplete orders to the next station or finalize them.
    4. Display station connections and current orders.

- **`LineManager` Class**:
  - Manages the entire assembly line.
  - **Tasks**:
    1. Parse a file to configure station connections.
    2. Identify the first station in the sequence.
    3. Move orders through the assembly line until all are processed.
    4. Display the sequence of stations and the status of processed orders.

---

### Implementation Notes
- **Input Files**:
  - Stations: Describes the inventory at each station.
  - Customer Orders: Specifies the items each customer requires.
  - Line Configuration: Defines how stations are connected.

- **Data Flow**:
  1. Load station and customer order data.
  2. Configure the assembly line.
  3. Process orders, filling items at each station.
  4. Track and display completed and incomplete orders.

- **Utilities Class**:
  - Handles token extraction and field formatting. Use this class to parse input files and manage delimiters.

---

### Testing
- Use the provided tester files to validate functionality:
  1. `tester_1_prof.cpp`: Tests `Station` and `Utilities`.
  2. `tester_2_prof.cpp`: Tests `CustomerOrder` and its interactions with `Station`.
  3. `tester_3_prof.cpp`: Tests `Workstation`, `LineManager`, and the full assembly line.

---

### Deliverables
- Submit all implemented classes and any helper functions.
- Ensure your program handles exceptions gracefully and adheres to the specified behavior.
- Include comments for clarity and maintain proper coding style.

---

[Workshop 4 detailed Explanation](ws4-detailed.md)