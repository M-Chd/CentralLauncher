#include "gameListWidget.hpp"

UI::GameListWidget::GameListWidget(QWidget* parent) : QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);

	QLabel* title = new QLabel("Ma Liste de Jeux", this);
	mainLayout->addWidget(title);

	QPushButton* addBtn = new QPushButton("Add Game", this);
	addBtn->move(2, 650);

}