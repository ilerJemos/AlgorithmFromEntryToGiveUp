from PIL import Image,ImageDraw,ImageFont

image = Image.open('resource/img/0.png')

w,h = image.size
font = ImageFont.truetype('arial.ttf',50)
draw =ImageDraw.Draw(image)
draw.text((2*w/5,3*h/5),'8',fill=(33,47,60),font = font)
#image.show()
image.save('resource/img/'
           '0.1.png','png')