#ifndef HEADER_TRACKWIDGET
#define HEADER_TRACKWIDGET

#include <QtGui>
#include "vtkRenderWindow.h"
#include "ui_DesignerTrackWidget.h"

#include <vtkstd/map>
#include "vtkPolyData.h"
#include "Lineage.h"

#include "vtkSphereSource.h"
#include "vtkCubeSource.h"

#include <string.h>

#include "vtkRendererCollection.h"

#include "TrackVisualization.h"

#include "vtkWindowToImageFilter.h"

#include <vtkFFMPEGWriter.h>

#include "vtkCommand.h"

#include <qlcdnumber.h>

#include "vtkSnapshotCommand.h"


class TrackWidget : public QWidget, private Ui::TrackWidget
{
    Q_OBJECT


    public:
        typedef vtkstd::map<double, vtkPolyData*> TrackType;

        TrackWidget(QWidget *parent = 0);
        ~TrackWidget();
        void SetRenderer (vtkRenderer *renderer);
        void SetRenderWindow (vtkRenderWindow *renderWindow);
        void SetRenderWindowInteractor (vtkRenderWindowInteractor *renderWindowInteractor);
        void SetTotalTimeRange(int value);
        void SetEndTime(int value);
        void SetGlyphTime(int value);
        void SetRootNode(Lineage<TrackType> * root);

    private:
        vtkRenderer *Renderer;
        vtkRenderWindow *RenderWindow;
        vtkRenderWindowInteractor *RenderWindowInteractor;
        bool tubesON, linesON;
        int Begin, End, TotalTimeRange, GlyphTime;
        int Shape;
        const char* FileName;
        int VideoQuality;
        int FrameRate;

        Lineage<TrackType>* RootNode;
        vtkFFMPEGWriter* FFMPEGWriter;
        vtkWindowToImageFilter* W2if;
        vtkSnapshotCommand* SnapshotObserver;

    private slots:
        void on_lines_clicked();
        void on_tubes_clicked();
        void on_tubes_toggled(bool on);
        void on_lines_toggled(bool on);
        void on_glyphShape_activated ( int index );
        void on_apply_clicked();
        void on_startVideo_clicked();
        void on_endVideo_clicked();
        void on_begin_valueChanged(int value);
	void on_end_valueChanged(int value);
	void on_totalTimeRange_valueChanged(int value);
	void on_videoQuality_valueChanged(int value);
	void on_frameRate_valueChanged(int value);
	void on_glyphTime_valueChanged(int value);
	void on_glyphTimeSlider_valueChanged(int value);

	void updateRenderingWindow();
};

#endif

