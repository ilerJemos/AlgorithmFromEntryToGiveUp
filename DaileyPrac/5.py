#iphone5 1136*640
#iphone6 1334*750
import os
from PIL import Image

ext = ['png','jpg','jpeg']
path ='resource/img'
files = os.listdir(path)

def process_image(filename,mwidth = 750,mhight=1334):
    image = Image.open(path+'/'+filename)
    image.show()
    w,h = image.size
    if w<h:
        new_image = image.resize((mwidth,mhight),Image.ANTIALIAS)
    else:
        new_image = image.resize((mhight, mwidth), Image.ANTIALIAS)
    #scale = max(w/mwidth*1.0,h/mhight*1.0)
    #new_image = image.resize((int(w / scale),int(h / scale)), Image.ANTIALIAS)
    new_image.show()
for file in files:
    if file.split('.')[-1] in ext:
        #print(file)
        process_image(file)