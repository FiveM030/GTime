/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <thread>

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

USING_NS_CC;

int year;
int mon;
int day;
int hour;
int min;
int sec;


Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 3. add your codes below...
    auto bg = CCLayerColor::create(ccc4(254, 255, 255, 255));
    this->addChild(bg, 0);

    auto color = Color3B(79, 155, 250);
    std::string syear = toZero(std::to_string(year));
    std::string smon = toZero(std::to_string(mon));
    std::string sday = toZero(std::to_string(day));
    std::string shour = toZero(std::to_string(hour));
    std::string smin = toZero(std::to_string(min));
    std::string ssec = toZero(std::to_string(sec));
    auto label = Label::create(shour + ":" + smin + ":" + ssec, "fonts/HarmonyOS_Sans_SC_Black.ttf", 72);
    label->setColor(color);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    this->addChild(label, 1, 100);
    auto label1 = Label::create(syear + "年" + smon + "月" + sday + "日", "fonts/HarmonyOS_Sans_SC_Bold.ttf", 24);
    label1->setColor(Color3B(101, 163, 240));
    label1->setPosition(Vec2(30, 20));
    label1->setAnchorPoint(Vec2(0, 0));
    this->addChild(label1, 1, 200);

    return true;
}

void HelloWorld::onEnter()
{
    Node::onEnter();
    
    HelloWorld::scheduleUpdate();
}

void HelloWorld::update(float dt)
{
    struct tm* tm;
    time_t timep;
    time(&timep);
    tm = localtime(&timep);
    int year = tm->tm_year + 1900;
    int mon = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int min = tm->tm_min;
    int sec = tm->tm_sec;
    
    std::string syear = toZero(std::to_string(year));
    std::string smon = toZero(std::to_string(mon));
    std::string sday = toZero(std::to_string(day));
    std::string shour = toZero(std::to_string(hour));
    std::string smin = toZero(std::to_string(min));
    std::string ssec = toZero(std::to_string(sec));
    Label* label = (Label*)this->getChildByTag(100);
    label->setString(shour + ":" + smin + ":" + ssec);
    Label* label1 = (Label*)this->getChildByTag(200);
    label1->setString(syear + "年" + smon + "月" + sday + "日");
}

std::string HelloWorld::toZero(std::string num)
{
    if (num == "0" || num == "1" || num == "2" || num == "3" || num == "4" ||
        num == "5" ||num == "6" || num == "7" || num == "8" || num == "9")
    {
        return "0" + num;
    }
    else return num;
}