#include <iostream>
using namespace std;
constexpr char nl = '\n';
class {
   bool m_trace = false;
public:
   auto& trace(bool value) {
      m_trace = value;
      return *this;
   }
   auto& operator<<(const char* message) {
      if (m_trace) cout << (message ? message : "(NULLstr)");
      return *this;
   }
   auto& operator<<(int val) {
      if (m_trace) cout << val;
      return *this;
   }
   auto& operator<<(double val) {
      if (m_trace) cout << val;
      return *this;
   }
   auto& operator<<(char ch) {
      if (m_trace) cout << ch;
      return *this;
   }
} tracer;
constexpr int ReadBufferSize = 50;
class Cstr {
public:
   static void cpy(char* des, const char* src) {
      while (*des++ = *src++); // strcpy (fix for gcc on linux
   }
   static int len(const char* str) {
      const char* end = str;
      while (*end++);
      return static_cast<int>(end - str) - 1;
   }
   static void allocNcpy(char*& des, const char* src) {
      des = new char[len(src) + 1];
      cpy(des, src);
   }
   static char* read(istream& is) { // reading any size of Cstr dynamically and return it
      char* data = new char[ReadBufferSize];
      char* str = data;
      int noOfBuffers = 1;
      bool done;
      do {
         done = true;
         cin.getline(str, ReadBufferSize, '\n'); // if cin fails, it means entry was greater than 50 chars
         if (cin.fail()) {
            noOfBuffers++;  // keep track of number of buffers to add
            char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1]; // allocate bigger memory
            Cstr::cpy(temp, data); // copy the already read test into temp
            delete[] data;  // delete the old (too short) memory
            data = temp;    // point to newly large allocated memory 
            str = data + (ReadBufferSize - 1) * (noOfBuffers - 1); // set the read pointer to continue reading the rest of text
            cin.clear();   // clear cin to read again
            done = false;  //we are not done yet
         }
      } while (!done);   // go back and continue reading if not done
      allocNcpy(str, data);
      delete[] data;
      return str;
   }

};
class Name {
private:
   char* m_value = nullptr;
public:
   Name(const char* value = nullptr) {
      if (value) {
         Cstr::allocNcpy(m_value, value);
      }
      tracer << "Creat " << m_value << nl;
   }
   Name(const Name& N) {
      tracer << "Copy " << N.m_value << nl << "   by calling: ";
      operator=(N);
   }
   Name& operator=(const Name& N) {
      if (this != &N) {
         tracer << "Assign " << m_value << " to " << N.m_value << nl;
         delete[] m_value;
         Cstr::allocNcpy(m_value, N.m_value);
      }
      return *this;
   }
   Name& operator=(Name&& N) {
      if (this != &N) {
         tracer << " Move assign " << N.m_value << " into " << m_value << " by assignment" << nl;
         delete[] m_value;
         m_value = N.m_value;
         N.m_value = nullptr;
      }
      return *this;
   }
   Name(Name&& N) {
      tracer << "(Move const), Take ownership of " << N.m_value << " in a new Name" << nl << "  by calling: ";
      operator=(move(N));
   }
   ostream& print(ostream& os)const {
      return os << (m_value ? m_value : "(NULLstr)");
   }
   istream& read(istream& is) {
      delete[] m_value;
      m_value = Cstr::read(is);
      return is;
   }
   ~Name() {
      tracer << "Remove " << (m_value ? m_value : "(NULLstr)") << " from memory" << nl;
      delete[] m_value;
   }
};
ostream& operator<< (ostream& os, const Name& N) {
   return N.print(os);
}
istream& operator>> (istream& is, Name& N) {
   return N.read(is);
}

int main() {
   tracer.trace(true);
   Name A;
   cout << "who are you? " << endl;
   tracer << "cin >> A;" << nl;
   cin >> A;
   cout << "hello " << A << endl;
   tracer << "Name B = move(A);" << nl;
   Name B = move(A);
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   tracer << "A = B;" << nl;
   A = B;
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   tracer << "A = move(B);" << nl;
   A = move(B);
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   return 0;
}
