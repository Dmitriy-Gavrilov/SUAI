#pragma once
// ���� rotatable.h
#ifndef ROTATABLE_H
#define ROTATABLE_H
class Rotatable { //������, ��������� � ��������
public:
	virtual void rotateLeft() = 0; //��������� �����
	virtual void rotateRight() = 0; //��������� ������
};
#endif // ROTATABLE_H