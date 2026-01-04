template<typename Iterator, typename Distance>
void safe_advance(Iterator& it, Iterator begin, Iterator end, Distance n) {
   if (n >= 0 && std::distance(it, end) >= n) {
      std::advance(it, n);
   }
   else if (n < 0 && std::distance(begin, it) >= -n) {
      std::advance(it, n);
   }
   else {
      throw std::out_of_range("Iterator advance out of bounds");
   }
}

/*
usage:

safe_advance(it, nums.begin(), nums.end(), 6); // Throws exception if out of bounds


*/