import re
import base64
import redis

def make_connect():
    r= redis.Redis(host='104.225.158.144',password='ilerjemos',port=6379)
    return r

def parse_coupon(c_code):
    return base64.urlsafe_b64decode(c_code.encode('utf-8'))

def upload_to_database():
    session = make_connect()
    print(session.get('iler'))
    return
    with open('1_coupon.txt','r')as file:
        for line in file.readlines():
            c_id = re.findall(r'.*/.*:(.*)\'',str(parse_coupon(line)))
            session.set(c_id.pop(),line.strip())

if __name__=='__main__':
    upload_to_database()