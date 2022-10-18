//switch case
type ParkingSystem struct {
	big    int
	medium int
	small  int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	var park ParkingSystem
	park.big = big
	park.medium = medium
	park.small = small
	return park
}

func (this *ParkingSystem) AddCar(carType int) bool {
	switch carType {
	case 1:
		{
			if this.big > 0 {
				this.big -= 1
				return true
			} else {
				return false
			}
		}
	case 2:
		{
			if this.medium > 0 {
				this.medium -= 1
				return true
			} else {
				return false
			}
		}
	case 3:
		{
			if this.small > 0 {
				this.small -= 1
				return true
			} else {
				return false
			}
		}
	}
	return false
}

/*------------------------使用数组-----------------------*/
type ParkingSystem struct {
	arr [3]int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{
		arr: [3]int{big, medium, small},
	}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	this.arr[carType-1]--
	return this.arr[carType-1] >= 0
}