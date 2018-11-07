#对着电脑吼一声,自动打开浏览器中的默认网站。
# 参考思路：
# 1.获取电脑录音-->wav文件 python record wav
# 2.录音文件转文本
#     STT: speech to text
#     STT: API google api
# 3.文本转点啊弄命令

import wave
# import pyaudio
import json
import uuid
import  base64
import webbrowser
from urllib.request import Request,urlopen,HTTPError,URLError

website={
    'www.baidu.com':'baidu,百度,白,度,',
    'www.weibo.com':"微博,微,博",
    'www.google.com':"谷歌,谷,歌"
}
