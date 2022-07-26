
from numpy import double


print("\n\n")

def std_weight(height, gender) :

    if height >= 100 :
        height /= 100
    
    value = height**2
    
    print('\n\n')
    if (gender == 'female' or gender == '여자' or gender == '여') :
        value *= 21
        print("sex : [female]")
    else :
        value *= 22
        print("sex : [male]")
    
    
    print(f"height : {height}m")
    print(f"standard weight : {value:.2f} kg")
    return


height = double(input("type your height : "))
gender = input("type your sex : ")

std_weight(height, gender)



print("\n\n")