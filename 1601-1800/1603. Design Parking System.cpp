// https://zxi.mytechroad.com/blog/simulation/leetcode-1603-design-parking-system/
class ParkingSystem {
public:
  ParkingSystem(int big, int medium, int small): 
    slots_{{big, medium, small}} {}
 
  bool addCar(int carType) {
    return slots_[carType - 1]-- > 0;
  }
private:
  vector<int> slots_;
};
