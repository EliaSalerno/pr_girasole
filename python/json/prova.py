import json

filename="temp.json"

a=22
b=24
c=25
d={"a":a,"b":b,"c":c}
# d=json.dumps(d,indent=4,sort_keys=True)
# print(d)

objfile=open(filename,"a")
json.dump(d,objfile)
objfile.close()

# here we create new data_file.json file with write mode using file i/o operation 
#with open('prova2.json', "w") as file_write:
# write json data into file
#	json.dump(d, file_write)

