# -*- coding: cp949 -*-
inputFile = open("input.txt", 'r') # 'r' �б� 'w' ���� 'a' ��
outputFile = open("output.txt", 'w')

while 1: 
    line = inputFile.readline()
    if not line: break
    
    words = line.split(' ')
    for word in (words):
        word = word.lstrip().rstrip() #�� �� ��������
        if not word: continue # word�� �����Ͱ� �ִ��� Ȯ��
        outputFile.write("%s\n" % word)

inputFile.close()
outputFile.close()
