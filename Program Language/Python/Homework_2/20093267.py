# -*- coding: cp949 -*-
import glob
import os

directoryPath = raw_input("Please enter directory path\n")
directoryPath = "%s\*.txt" %directoryPath

files = glob.glob(directoryPath) 

outputFile = open("all_files.txt", 'w')
for fileName in (files):
    inputFile = open(fileName, 'r') # 'r' �б� 'w' ���� 'a' �߰�

    wordCount = 0
    lineCount = 0
    while 1: 
        line = inputFile.readline()
        line = line.strip()
        if not line: break
        lineCount+=1
        outputFile.write(line)
        words = line.split(' ')
        for word in (words):
            word = word.strip() #�� �� ��������
            if not word: continue # word�� �����Ͱ� �ִ��� Ȯ��
            wordCount+=1

    print("FileName : %s, Word : %d, Line : %d" %(os.path.basename(fileName),wordCount,lineCount) )
    inputFile.close()

outputFile.close()
