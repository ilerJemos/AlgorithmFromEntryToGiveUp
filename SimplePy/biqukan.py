import requests
from bs4 import BeautifulSoup
from lxml import etree
import sys
##已完成功能
##获取小说url,将内容保存在txt中
##待加功能
##多线程
class downloader(object):
    def __init__(self):
        self.server="https://www.biqukan.com"
        self.target = "https://www.biqukan.com/1_1094/"
        self.names = []
        self.urls =[]
        self.nums =0;

#获取下载地址
    def get_download_url(self):
        req = requests.get(url=self.target)
        html = req.text
        div_bf = BeautifulSoup(html,'lxml')
        div = div_bf.find_all('div',class_='listmain')
        a_bf = BeautifulSoup(str(div[0]),'lxml')
        a=a_bf.find_all('a')
        self.nums = len(a[15:20])

        for each in a[15:20]:
            self.names.append(each.string)
            self.urls.append(self.server + each.get('href'))
#获取小说章节内容
    def get_contents(self, target):
        req = requests.get(url=target)
        html = req.text
        bf = BeautifulSoup(html,'lxml')
        texts = bf.find_all('div', class_='showtxt')
        texts = texts[0].text.replace('\xa0' * 8, '\n\n')
        return texts
#存入文件
    def writer(self, name, path, text):
        write_flag = True
        with open(path, 'a', encoding='utf-8') as f:
            f.write(name + '\n')
            f.writelines(text)
            f.write('\n\n')

if __name__ == '__main__':
    dl = downloader()
    # dl.get_download_url()
    # print("一年永恒 开始下载")
    # for i in range(dl.nums):
    #     dl.writer(dl.names[i],'resource/一念永恒.txt',dl.get_contents(dl.urls[i]))
    #     sys.stdout.write("已下载;%.3f"% float(i/dl.nums)+'\r')
    #     sys.stdout.flush()
    # print("小说下载完成！")
    req = requests.get(url="https://www.biqukan.com/1_1094/5403177.html")
    html = req.text
    bf = BeautifulSoup(html, 'lxml')
    texts = bf.find_all('div', class_='showtxt')
    #texts = texts[0].text.replace('\xa0' * 8, '\n\n')
    print(texts)
