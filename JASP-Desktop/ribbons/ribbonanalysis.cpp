#include "ribbonanalysis.h"
#include "ui_ribbonanalysis.h"

#include <QMenu>
#include <QDebug>

RibbonAnalysis::RibbonAnalysis(QWidget *parent) :
	RibbonWidget(parent),
	ui(new Ui::RibbonAnalysis)
{
	ui->setupUi(this);

	ui->bayesianPanel->hide();
	//ui->bayesianSeparator->hide();

	connect(ui->Descriptives, SIGNAL(clicked()), this, SLOT(itemSelected()));

	QMenu *menu;

	menu = new QMenu(this);
	menu->addAction(QString("Independent Samples T-Test"), this, SLOT(itemSelected()))->setObjectName("TTestIndependentSamples");
	menu->addAction(QString("Paired Samples T-Test"), this, SLOT(itemSelected()))->setObjectName("TTestPairedSamples");
	menu->addAction(QString("One Sample T-Test"), this, SLOT(itemSelected()))->setObjectName("TTestOneSample");

	menu->addSeparator();

	menu->addAction(QString("Bayesian Independent Samples T-Test"), this, SLOT(itemSelected()))->setObjectName("TTestBayesianIndependentSamples");
	menu->addAction(QString("Bayesian Paired Samples T-Test"), this, SLOT(itemSelected()))->setObjectName("TTestBayesianPairedSamples");
	menu->addAction(QString("Bayesian One Sample T-Test"), this, SLOT(itemSelected()))->setObjectName("TTestBayesianOneSample");

	ui->classicalTTestButton->setMenu(menu);


	menu = new QMenu(this);

	menu->addAction(QString("ANOVA"), this, SLOT(itemSelected()))->setObjectName("Anova");
	menu->addAction(QString("Repeated Measures ANOVA"), this, SLOT(itemSelected()))->setObjectName("AnovaRepeatedMeasuresShort");
	menu->addAction(QString("ANCOVA"), this, SLOT(itemSelected()))->setObjectName("Ancova");

	menu->addSeparator();

	menu->addAction(QString("Bayesian ANOVA"), this, SLOT(itemSelected()))->setObjectName("AnovaBayesian");
	menu->addAction(QString("Bayesian Repeated Measures ANOVA"), this, SLOT(itemSelected()))->setObjectName("AnovaRepeatedMeasuresBayesian");
	menu->addAction(QString("Bayesian ANCOVA"), this, SLOT(itemSelected()))->setObjectName("AncovaBayesian");

	ui->classicalAnovaButton->setMenu(menu);


	menu = new QMenu(this);

	menu->addAction(QString("Correlation Matrix"), this, SLOT(itemSelected()))->setObjectName("Correlation");
#ifdef QT_DEBUG
	menu->addAction(QString("Partial Correlation"), this, SLOT(itemSelected()))->setObjectName("CorrelationPartial");
#endif
	menu->addAction(QString("Linear Regression"), this, SLOT(itemSelected()))->setObjectName("RegressionLinear");

	menu->addSeparator();

	menu->addAction(QString("Bayesian Correlation Matrix"), this, SLOT(itemSelected()))->setObjectName("CorrelationBayesian");
#ifdef QT_DEBUG
	menu->addAction(QString("Bayesian Correlation Pairs"), this, SLOT(itemSelected()))->setObjectName("CorrelationBayesianPairs");
#endif
	menu->addAction(QString("Bayesian Linear Regression"), this, SLOT(itemSelected()))->setObjectName("RegressionLinearBayesian");

	ui->classicalRegressionButton->setMenu(menu);


	menu = new QMenu(this);

	menu->addAction(QString("Contingency Tables"), this, SLOT(itemSelected()))->setObjectName("Crosstabs");
	menu->addSeparator();
	menu->addAction(QString("Bayesian Contingency Tables"), this, SLOT(itemSelected()))->setObjectName("CrosstabsBayesian");

	ui->classicalCrosstabsButton->setMenu(menu);
}

RibbonAnalysis::~RibbonAnalysis()
{
	delete ui;
}
