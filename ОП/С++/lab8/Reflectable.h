#pragma once
// ���� reflectable.h
#ifndef REFLECTABLE_H
#define REFLECTABLE_H
class Reflectable { // ������, ��������� � ����������� ���������
public:
	virtual void flipHorisontally() = 0; // �������� �������������
	virtual void flipVertically() = 0; // �������� �����������
};
#endif // REFLECTABLE_H