import sys
import os
import shutil

path = "./templates"
dst_path = sys.argv[1] + "_" + sys.argv[2]
print("new dir name:", dst_path)
if (not os.path.exists(dst_path)):
    os.mkdir(dst_path)
for files in os.listdir(path):
    name = os.path.join(path, files)
    dst_name = os.path.join(dst_path, files)
    shutil.copy(name, dst_path)

