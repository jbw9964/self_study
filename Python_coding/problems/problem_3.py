





print("\ncode_started\n")

given_string = input("type the url : ")
print(given_string)

temp = given_string.index("/")
temp = given_string.index("/", temp + 1)

temp_1 = given_string.index(".")

raw_string = given_string[temp + 1 : temp_1]

length = len(raw_string)
count = raw_string.count("e")

print(f"{raw_string[:3]}{length}{count}!")


print("\ncode_ended\n")