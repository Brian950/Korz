#include "storythread.h"
#include "QDebug"
#include "storythread.h"

StoryThread::StoryThread(QObject *parent) : QThread(parent)
{
    tut_text_position = 0;
    part_1_complete = false;
    part_2_complete = false;
    part_3_complete = false;
}

void StoryThread::run()
{
    if(part_1_complete == false){
        load_file(tut_text_ptr);
        tutorial_part_1(tut_text_ptr);
    }
    else if(part_2_complete == false){
        tutorial_part_2(tut_text_ptr);
    }
    else if(part_3_complete == false){
        tutorial_part_3(tut_text_ptr);
    }
    else if(part_4_complete == false){
        tutorial_part_4(tut_text_ptr);
    }
}

void StoryThread::load_file(QStringList &tut_text_ptr){
    QFile inputFile("/home/brian/Korz/trunk/Korz/tutorial_story.txt");
    QString line;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          line = in.readLine();
          tut_text_ptr << line;
       }
       inputFile.close();
    }
}

void StoryThread::tutorial_part_1(QStringList &tut_text_ptr)
{
    QString line;
    for(int x = 0; x < 3; x++){
        line = tut_text_ptr.at(x);
        emit update_story(line);
        tut_text_position++;
        sleep(1);
    }
    emit spawn_tutorial_rects();
    part_1_complete = true;
}

void StoryThread::tutorial_part_2(QStringList &tut_text_ptr)
{
    QString line;
    for(int x = tut_text_position; x < 5; x++){
        line = tut_text_ptr.at(x);
        emit update_story(line);
        if(x != 5-1)
            sleep(1);
        tut_text_position = x;
    }
    part_2_complete = true;
}

void StoryThread::tutorial_part_3(QStringList &tut_text_ptr)
{
    QString line;
    for(int x = tut_text_position; x < 8; x++){
        line = tut_text_ptr.at(x);
        emit update_story(line);
        sleep(1);
        tut_text_position = x;
    }
    emit spawn_tutorial_enemy();
    part_3_complete = true;
}

void StoryThread::tutorial_part_4(QStringList &tut_text_ptr)
{
    QString line;
    for(int x = tut_text_position; x < 10; x++){
        line = tut_text_ptr.at(x);
        emit update_story(line);
        sleep(1);
        tut_text_position = x;
    }
    emit spawn_tutorial_enemy();
    part_4_complete = true;
}
