// https://zxi.mytechroad.com/blog/data-structure/leetcode-1845-seat-reservation-manager/
class SeatManager {
public:
  SeatManager(int n) {
    for (int i = 1; i <= n; ++i)
      s_.insert(i);
  }
 
  int reserve() {    
    int seat = *begin(s_);
    s_.erase(begin(s_));    
    return seat;
  }
 
  void unreserve(int seatNumber) {
    s_.insert(seatNumber);    
  }
private:
  set<int> s_;
};
