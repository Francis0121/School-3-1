# coding: cp949
pocket = ['paper', 'money', 'handphone']
watch = 1
if 'money' in pocket:
    print("�ýø� Ÿ�� ����")
elif 'book' not in pocket:
    pass
elif watch:
    print("�ýø� Ÿ�� ����")
else:
    print("�ɾ� ����")

coffee = 10
money = 300
while money:
    print("���� �޾����� Ŀ�Ǹ� �ݴϴ�.")
    coffee = coffee - 1
    print("���� Ŀ���� ���� %d �Դϴ�." % coffee)
    if not coffee:
        print("Ŀ�ǰ� �� ���������ϴ�. �ǸŸ� �����մϴ�.")
        break
