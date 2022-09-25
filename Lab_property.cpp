#include <iostream>
#include <vector>
using namespace std;

/* логіка прогнозування:
  * 1) обчислюємо середнє арифметичне для кожного типу даних;
  * 2) виберемо вибірку нерухомості з однаковою кількістю спальних кімнат
  * 3) за методом лінійної регресії обчислимо приблизну ціну
  * 4) порівняємо дві будь-які квартири з даної вибірки для того, щоб обчислити залежність ціни квартири від часу, за який можна дібратися до метро
  * 5) на цю залежність також впливають інші чинники, тоді візьмемо coef_time*ціну за хв.
  * 6) видаємо прогнозовану ціну
  */

double predict(vector<Property>&vector, struct Property&predicting) {
    double target;
    int num_Of_Points = vector.size();
    double sumX=0, sumX2=0, sumY=0, sumXY=0;

    //обчислення коефіцієнтів k та b
    for(int i = 0;i < num_Of_Points ;i++)
    {
        sumX = sumX + vector[i].area;
        sumX2 = sumX2 + vector[i].area*vector[i].area;
        sumY = sumY + vector[i].target;
        sumXY = sumXY + vector[i].area*vector[i].target;
    }

    double k = (num_Of_Points*sumXY-sumX*sumY)/(num_Of_Points*sumX2-sumX*sumX);
    double b = (sumY - k*sumX)/num_Of_Points;

    target = k * predicting.area + b;

    {
        const double coef_time = 0.1;

        int gap_time = fabs(vector[vector.size()/2].time - vector[vector.size()/2 + 1].time);

        double gap = fabs((vector[vector.size()/2].target - vector[vector.size()/2 + 1].target)/gap_time);
        if(gap>1000){
            gap *=coef_time;
        }

        target -= fabs(coef_time*(gap_time-predicting.time)*gap);
    }

    return target;
}

bool sanity_check(double area, int bed, int toilet, int time, double target){

    const double area_min = 10.0;
    const double area_max = 500.0;

    const int room_min = 1;
    const int room_max = 5;

    const int time_min = 1;
    const int time_max = 100;

    const double target_min = 10000.0;
    const double target_max = 1000000.0;

    bool area1 = ((area >= area_min) && (area <= area_max));
    bool bed1 = ((bed >= room_min) && ( bed <= room_max));
    bool toilet1 = ((toilet >= room_min)  && (toilet <= room_max));
    bool time1 = ((time >= time_min) && (time <= time_max));
    bool target1 = (target >= target_min) && (target <= target_max);
    bool all = (area1 && bed1 && toilet1 && time1 && target1);

    return all;
}


void sort(vector<Property>&vector, struct Property&predicting){
    for(int i = 0; i< vector.size(); i++){
        if((vector[i].bed != predicting.bed) || (abs(vector[i].area - predicting.area) > 25) ){
            vector.erase(vector.begin() + i);
            i--;
        }
    }
}

struct Property{ // структура для вектора
    double area;
    int bed;
    int toilet;
    int time;
    bool habitable;
    double target;
};

int main() {

    int i = 0;
    Property predicting;
    double area;
    int bed;
    int toilet;
    int time;
    bool habitable;
    double target;
    vector<Property> vector;

    cout <<"If you want to stop entering the vector, enter 0 for the area and then enter data to prognose the target." << endl;

    //вводимо вектор і перевіряємо його за допомогою sanity_check
    do{
        cout << endl << "Please enter the data for " << i+1 << " element of vector using this pattern(area, bed rooms, toilet rooms, time to metro, habitable, target) through the space:" << endl;
        cin >> area;
        if(area == 0){
            break;
        }
        cin >> bed >> toilet >> time >> habitable >> target;

        bool sanity_check1 = sanity_check(area, bed, toilet, time, target);

        if (sanity_check1) {
            vector.push_back({area, bed, toilet, time, habitable, target});
        }
        else{
            cout << "Enter another data, this data hasn't passed sanity check";

        }
        i++;

    }while(true);

    {

        //вводимо дані для прогнозування
        cout << "Now enter the data to prognose the data:";
        cin >> area >> bed >> toilet >> time >> habitable;
        bool sanity_check1 = sanity_check(area, bed, toilet, time, 10000);
        if (sanity_check1) {
            predicting.area = area;
            predicting.bed = bed;
            predicting.toilet = toilet;
            predicting.time = time;
            predicting.habitable = habitable;
            predicting.target = 0;
        }
        else{
            cout << "Enter another data, this data hasn't passed sanity check";
        }

    }

    sort(vector, predicting);

    cout << endl << "The predicted price is: " << predict(vector, predicting);

    return 0;
}
