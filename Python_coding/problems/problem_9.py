

print('\n\n')

class SoldOutError(Exception) :
    def __init__(self, message) -> None:
        self.message = message

    def __str__(self) -> str:
        return self.message

Left_Chiken = 10
Waiting_no = 0

while True :
    
    try :

        if Left_Chiken == 0 :
            raise SoldOutError("Every chicken has been sold.\nThank you for visiting.\n")
            
        Order = int(input("How many Chikens you want to order? : "))

        if type(Order) != int or Order < 1:
            raise ValueError

        try :
            if Left_Chiken - Order < 0 :
                raise SoldOutError(f"Left Chickens are only {Left_Chiken}. Please order less than {Left_Chiken}\n")
            
            Waiting_no += 1
            Left_Chiken -= Order
            print(f"Your waiting number is : [{Waiting_no}]")
            print(f"There are [{Left_Chiken}] Chickens left.\n")
        except SoldOutError as Err :
            print(Err)
        except :
            print("Unexpected Error has been occurred\n")

    except ValueError :
        print("You put wrong input. Try again.\n")
    except SoldOutError as Err :
        print(Err)
        break
    except :
        print("Unexpected Error has been occurred\n")

    
    
    

    






print('\n\n')