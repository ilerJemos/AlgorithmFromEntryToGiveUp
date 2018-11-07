from PIL import Image, ImageDraw, ImageFont


def add_num(filename, text='9', size=40, color='red'):
    image = Image.open(filename)
    w, h = image.size
    font = ImageFont.truetype('arial.ttf', size)
    draw = ImageDraw.Draw(image)
    draw.text((2 * w / 5, 3 * h / 5), text, fill=color, font=font)
    name = filename.split('/')[-1]
    path = filename.split('/')[:-1]
    fullpath = ''
    for p in path:
        fullpath += p
        fullpath += '/'
    newname =fullpath+ 'new_'+name
    image.save(newname)

if __name__ == '__main__':
   if add_num("resource/img/0.png"):
       print("success!!")
