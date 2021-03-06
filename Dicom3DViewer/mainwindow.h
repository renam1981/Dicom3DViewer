#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>  
#include <QDir>
#include <qcolordialog.h>

#include "ui_mainwindow.h"
#include "volumeRenderProcess.h"
#include "colorTransferFunction.h"
#include "opacityTransferFunction.h"
#include "dicomVisualizer.h"
#include "roiVisualizer.h"
#include "boundVisulizer.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
	VolumeRenderProcess * vrProcess;
	ColorTransferFunction * colorTf;
	OpacityTransferFunctioin * opacityTf;
	OpacityTransferFunctioin * gradientTf;

	DicomVisualizer * dicomVisualizer;
	RoiVisualizer * roiVisualizer;
	BoundVisualizer * boundVisualizer;

	int niiOrDicom; // 0 for nii, 1 for dicom
	

private slots:
	void onOpenDicomFolderSlot();
	void onOpenDiiFileSlot();

	void onCacheVolumeSlot();
	void onShowVolumesSlot();
	void onClearCacheSlot();

	void onSetBgColorSlot();

	void onSetBoneStyle();
	void onSetBone2Style();
	void onSetSkinStyle();
	void onSetMuscleStyle();

	void onSetSmartMapper();
	void onSetRayCastMapper();

	bool eventFilter(QObject *, QEvent *);
	void onShowColorBpInfoAt(int);
	void onShowOpacityBpInfoAt(int);
	void onShowGradientBpInfoAt(int);

	void onDicomSeriesSlideMoveSlot(int);
	void onGradientThreshSlideMoveSlot(int);

	void onBoundExtractionButton();
	void onRoiGrayMinChangeSlot(int);
	void onRoiGrayMaxChangeSlot(int);
	void onKMeansSlot();

	void onRoiToBoundSlot();
	void onMagThreshMinChangeSlot(int);
	void onMagThreshMaxChangeSlot(int);

	void onRoiRenderSlot();
	void onRoiIncreaseRenderSlot();
	void onRoiBoundRenderSlot();
	void onRoiBoundIncreaseRenderSlot();
	void onResetGradientTfSlot();
};

#endif // MAINWINDOW_H
