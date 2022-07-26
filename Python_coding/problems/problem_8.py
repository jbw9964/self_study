
print('\n\n')

class House() :

    def __init__(self, location = None, house_type = None, deal_type = None, price = None, completion_year = None) -> None:
        self.location = str(location)
        self.house_type = str(house_type)
        self.deal_type = str(deal_type)
        self.price = str(price)
        self.completion_year = str(completion_year)
        self.is_sold = False

    def show_detail(self) :
        print("----------------------------")       # 28
        print("location".ljust(15), (self.location).rjust(7), sep=' : ', end='\n')
        print("house_type".ljust(15), (self.house_type).rjust(7), sep=' : ', end='\n')
        print("deal_type".ljust(15), (self.deal_type).rjust(7), sep=' : ', end='\n')
        print("price".ljust(15), (self.price).rjust(7), sep=' : ', end='\n')
        print("completion_year".ljust(15), (self.completion_year).rjust(7), sep=' : ', end='\n')
        print("is_sold".ljust(15), str((self.is_sold)).rjust(7), sep=' : ', end='\n')
        print("----------------------------")

    def purchase(self) :
        self.is_sold = True
        print(f"[{self.location.ljust(3)} {self.house_type.ljust(4)} {self.deal_type.ljust(3)} {self.price.ljust(3)} {self.completion_year.ljust(5)}] has been sold\n")

class HOUSES(House) :

    Size = 0

    def __init__(self) -> None:
        self.House_List = []

    def append(self, *input) :
        self.Size += 1
        temp = super().__init__(input[0], input[1], input[2], input[3], input[4], input[5])
        try :
            if input[6] :
                temp.is_sold = True
        except :
            print("in input, there is no data about".ljust(25), "is_sold".rjust(7), sep=" : ", end='\n')
            print("set House's is_sold as default".ljust(25), "False".rjust(7), sep=" : ", end='\n')
        
        self.House_List.append(temp)
    def append(self, house) :
        self.Size += 1
        if type(house) == type(house) :
            temp = House(house.location, house.house_type, house.deal_type, house.price, house.completion_year)
            if house.is_sold :
                temp.is_sold = True

        self.House_List.append(temp)

    def purchase(self, input) :
        if input > self.Size :
            print(f"There are {self.Size} Houses in List. There's no match with your input : {input}\n")
            return

        self.House_List[input - 1].purchase()
        self.House_List[input - 1].show_detail()

    def show_detail(self) :
        
        print(f"There are {self.Size} Houses in List\n")
        list_count = 0
        if self.Size == 0 : return
        print(str.center('', 28, '-'))
        for count in self.House_List :
            print(str.center(f"{list_count + 1}", 28, "="))
            count.show_detail()
            list_count += 1
        print('\n')

    def remove(self, input) :
        if input > self.Size :
            print(f"There are {self.Size} Houses in List. There's no match with your input : {input}\n")
            return

        temp = self.House_List[input - 1]
        self.House_List.remove(self.House_List[input - 1])
        self.Size -= 1
        print(f"[{temp.location.ljust(3)} {temp.house_type.ljust(4)} {temp.deal_type.ljust(3)} {temp.price.ljust(3)} {temp.completion_year.ljust(5)}] has been removed\n")
        del temp

    def Dispose(self) :
        self.House_List.clear()
        self.Size = 0
        print("House list has been cleaned\n")




temp_1 = House('강남', '아파트', '매매', '10억', '2010년')
temp_2 = House('마포', '오피스텔', '전세', '5억', '2007년')
temp_3 = House('송파', '빌라', '월세', '500/50', '2000년')

temp_list = HOUSES()
temp_list.append(temp_1)
temp_list.append(temp_2)
temp_list.append(temp_3)
temp_list.show_detail()

temp_list.remove(2)
temp_list.show_detail()



print('\n\n')