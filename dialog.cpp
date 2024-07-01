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
         long long synaps = line.toLongLong(&ok);
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
        goto d;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: решение
//////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
b:
    for ( var = 100; 
   var < 200

     ; ++var) // This is the range of neurons

    {
        for ( neuron_index = 0, synapse_index = 0;

          /*,*/ synapse_index < 10100; 
            ++neuron_index, synapse_index = synapse_index + 100)
        
        { // // ошибка сегментации
        

        if (neuron_index < 200)
            list_of_neurons[var]=list_of_neurons[var] //-5310911
            +  (list_of_neurons[neuron_index]/  
             list_of_synapses[synapse_index]); // + на - 
              
        } // 
    }
//////////////////////
    for (int   neuron_index = 100, synapse_index = 10000;

 synapse_index < 10100
 ; 
      ++neuron_index, ++synapse_index)
    {
   if (list_of_synapses[synapse_index]!=0)
        list_of_neurons[200] = list_of_neurons[200] //-5310911
        + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index])
        ; // + на -
    }    
//########################################################################################################    
//########################################################################################################
/////////////   показываем что определила программа
    if 
      //  ( variable_error <=0)
        (list_of_neurons[200]<0)

    { 
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
               if (variable_synapse_index_counter>0) // вот была ошибка
       {
       // если все синапсы пройдены, поставлены на минимумы и ошибка не пропала.
             if (list_of_synapses[variable_synapse_index_counter] < 9223372036854775807 // почему 2147483646?
             && list_of_synapses[variable_synapse_index_counter] >0
             ) // < 2147483646 или > 1
     {
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]-1;  // +1 или -1
        variable_synapse_index_counter--;
        std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
       goto b;   
     }
     }
        else
      {
       std::cout << "все синапсы пройдены, поставлены на минимумы и ошибка не пропала." << std::endl;
       all_sinapsi_proydeni=true;
       std::cout << "list_of_neurons[200] = " <<list_of_neurons[200]<< std::endl;
   }
       // Odin_Programmi=true;
    }
                           else {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
        //  Odin_Programmi=false;
        goto d;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

d: ;;
//########################################################################################################  
// перезапишем синапсы
auto it = list_of_synapses.begin();
size_t idx = std::distance(list_of_synapses.begin(), it);
// std::cout << "Текущий индекс синапсов: " << idx<<std::endl; 
 auto it2 = list_of_neurons.begin();
size_t idx2 = std::distance(list_of_neurons.begin(), it2);
// std::cout << "Текущий индекс нейронов: " << idx2<<std::endl;
//########################################################################################################
    QFile file3( "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
    if (!file3.open(QFile::WriteOnly | QFile::Truncate)) {
        throw std::runtime_error("Failed to open file");
    }

    QTextStream out(&file3);
    for ( long long synapse : list_of_synapses) {
       out << synapse << "\n";
   }

   file3.close();
 //########################################################################################################
           std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
           if (all_sinapsi_proydeni==true)
           std::cout << "все синапсы пройдены, поставлены на минимумы и ошибка не пропала." << std::endl;
                   std::cout << "Конец программы." << std::endl;








}

Dialog::~Dialog()
{
    delete ui;
}

