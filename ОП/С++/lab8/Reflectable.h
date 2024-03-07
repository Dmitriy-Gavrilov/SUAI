#pragma once
// Файл reflectable.h
#ifndef REFLECTABLE_H
#define REFLECTABLE_H
class Reflectable { // Фигуры, пригодные к зеркальному отражению
public:
	virtual void flipHorisontally() = 0; // Отразить горизонтально
	virtual void flipVertically() = 0; // Отразить вертикально
};
#endif // REFLECTABLE_H