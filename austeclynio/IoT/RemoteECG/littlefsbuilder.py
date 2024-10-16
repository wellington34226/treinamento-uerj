Import("env")
Import("os")
for root, dirs, files in os.walk("./data_original"):
  for fileName in files:
    if fileName.endswith("min.json") or fileName.endswith("min.js") or fileName.endswith("min.css") or fileName.endswith("min.html"):
      newFileName = os.path.join(root.replace("data_original","data"),fileName.replace(".min.","."))
      oldFileName = os.path.join(root,fileName)
      os.rename(oldFileName, newFileName)
env.Replace( MKSPIFFSTOOL='mklittlefs.exe' )