// 11장-7.HIERAR.CPP의 첫 번째 부분  11.6 예외 class의 계층 구조
class RangeError {};
class MonthRange : public RangeError {};
class MonthTooBig : public MonthRange {};
class NegativeMonth : public MonthRange {};
class DayRange : public RangeError {};
class DayTooBig : public DayRange {};
class DayTooBigForMonth : public DayTooBig {};
class NegativeDay : public DayRange {};