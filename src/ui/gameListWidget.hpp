#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <qpushbutton.h>

namespace UI {
	class GameListWidget : public QWidget
	{
		Q_OBJECT
	public:
		explicit GameListWidget(QWidget* parent = nullptr);

	private:
		QVBoxLayout* mainLayout;
	};
}