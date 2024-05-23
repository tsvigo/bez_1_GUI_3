//########################################################################################################
#include "dialog.h"
#include "ui_dialog.h"
//########################################################################################################
#include <fstream>
#include <iostream>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
using namespace std;
#include <unistd.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int variable_synapse_index_counter=10100; 
long long variable_error;
int var =100;
 int neuron_index = 0, synapse_index = 0;
QString Nazvaniye_fayla_s_neyronami_i_signalom;
std::vector<long long> list_of_neurons={};
std::vector<long long> list_of_synapses={};
bool all_sinapsi_proydeni=false;
//########################################################################################################

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
    std::cout << "bez_1_GUI_3" << std::endl;  
//######################################################################################################## 
/// Сначала укажем какой файл с нейронами подстроить.
     Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
       tr("Открыть файл neyroni_i_signal.txt без 1 который надо подстроить."), 
       "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/", tr("Text Files (*.txt)"));
//########################################################################################################
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор
const QString& fileName=Nazvaniye_fayla_s_neyronami_i_signalom;
    std::ifstream file(fileName.toStdString().c_str());
    if (file.is_open()) {
         long long value;
        while (file >> value) {
            list_of_neurons.push_back(value);
        }
        file.close();
    } else {
        qDebug() << "Unable to open file: " << fileName;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// загрузка синапсов из файла в вектор
    QFile file2(  
    "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
   //  "/home/viktor/my_scripts_4/kraynie_znacheniya/sinapsy_2147483647.txt"
  //  "/home/viktor/my_scripts_4/kraynie_znacheniya/sinapsy_1.txt"
    );
    if (!file2.open(QFile::ReadOnly | QFile::Text)) {
        throw std::runtime_error("Failed to open file");
    }

    QTextStream in(&file2);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
         long long synaps = line.toULongLong(&ok);
        if (!ok) {
            throw std::runtime_error("Invalid synaps value in file");
        }
        list_of_synapses.push_back(synaps);
    }

    file2.close();
//########################################################################################################
/////////////   показываем что определила программа
    if 
      //  ( variable_error <=0)
        (list_of_neurons[200]<0)

    {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
       // Odin_Programmi=true;
    }
                           else {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
        //  Odin_Programmi=false;
    }














}

Dialog::~Dialog()
{
    delete ui;
}

