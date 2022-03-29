import os
import platform

text = open(".vscode/tasks.json").read()
tocompare1 = '"args": ['
text.find(tocompare1)
ind = text.find(tocompare1)+8
inside = False
argslist = []
currtxt = ""
while (text[ind] != "]"):
    currchar = text[ind]
    if inside:
        if currchar == '"':
            inside = False
            argslist.append(currtxt)
            currtxt = ""
        else:
            currtxt += currchar
    else:
        if currchar == '"':
            inside = True
    ind += 1
for i in range(len(argslist)):
    argslist[i] = argslist[i].replace("${workspaceFolder}",os.getcwd())
final = "g++"
def apend(tx):
    for i in range(len(argslist)):
        if argslist[i].find("minecraftcompiled") != -1:
            argslist[i]+=tx
if platform.system() == "Windows": 
    apend(".exe")
    for i in range(len(argslist)):
        argslist[i] = argslist[i].replace("/usr/local/include/","C:\\MinGW\\include\\")
        argslist[i] = argslist[i].replace("/usr/include/","C:\\MinGW\\include\\")
        argslist[i] = argslist[i].replace("/usr/local/lib/","C:\\MinGW\\lib\\")
        argslist[i] = argslist[i].replace("/","\\")
for i in argslist:
    final += " "+i
os.system(final)
