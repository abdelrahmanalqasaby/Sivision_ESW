#include<iostream>
#include<thread>
#include<queue>

using namespace std;


enum prioity_enum
{
    LOW,
    MEDIUM,
    HIGH
};

class EventBase
{
private:
    int priority;
public:
    EventBase(int p):priority(p)
    {

    }
    virtual void executeFunction()=0;
    void setupHardware()
    {
    std::cout << "Hardware Setup  Called\n";
    }

    void setupSystem()
    {
    std::cout << "System Setup Called\n";
    }
    int getPriority()
    {
        return priority;
    }
    virtual ~EventBase()
    {

    }
};
class HardwareSendPacket : public EventBase
{
public:
    HardwareSendPacket():EventBase(HIGH)
    {

    }
    void executeFunction() override
    {
        EventBase::setupHardware();
        cout<<"HardwareSendPacket is executing "<<endl;
    }

};
class HardwareReceivePacket:public EventBase
{
public:
    HardwareReceivePacket():EventBase(LOW)
    {

    }
    void executeFunction() override
    {
        EventBase::setupHardware();
        cout<<"HardwareReceivePacket is executing "<<endl;
    }

};
class SystemSleep:public EventBase
{
public:
    SystemSleep():EventBase(HIGH)
    {

    }
    void executeFunction() override
    {
        EventBase::setupSystem();
        cout<<"SystemSleep is executing \n";
    }

};
class SystemWakeup:public EventBase
{
public:
    SystemWakeup():EventBase(MEDIUM)
    {

    }
    void executeFunction() override
    {
        EventBase::setupSystem();
        cout<<"SystemWakeup is executing \n";
    }

};
class SystemShutdown:public EventBase
{
public:
    SystemShutdown():EventBase(LOW)
    {

    }
    void executeFunction() override
    {
        EventBase::setupSystem();
        cout<<"SystemShutdown is executing \n";
    }

};

class comparator
{
public:
    bool operator()(EventBase* ob1,EventBase* ob2)
    {
        return ob1->getPriority() < ob2->getPriority();
    }
};
std::priority_queue<
    EventBase*,
    std::vector<EventBase*>,
    comparator
>MyQueue;

class EventManager
{
private:
    //std::thread* type1Thread;

    EventManager()
    {
    }

public:
    static EventManager& creatObject() //singleton object
    {
        static EventManager object;
        return object;
    }
    void postEvent(EventBase* EventObj)
    {
        MyQueue.push(EventObj);
        cout<<"element pushed";
    }
    void startHandlingEvents()
    {
        //type1Thread = new std::thread(&EventManager::loop_func, this);
        int limit=MyQueue.size();
        for(int i=0;i<limit;i++)
        {
            //cout<<"MyQueue.size()"<<MyQueue.size()<<endl;
            EventBase* event=MyQueue.top();
            MyQueue.pop();
            event->executeFunction();
            //cout<<"\nEvent manager loop function\t"<<event->getPriority()<<endl;
        }
    }

    void stopHandlingEvents()
    {
        //type1Thread -> join();
        //delete type1Thread;

    }
    void loop_func()
    {
        for(int i=0;i<MyQueue.size();i++)
        {
            cout<<MyQueue.size();
            EventBase* event=MyQueue.top();
            MyQueue.pop();
            cout<<"Event manager loop function\t"<<event->getPriority()<<endl;
        }
    }


};

class EventGenerator
{
private:
    //std::thread* type2Thread;

    int freq;
    EventBase* EventObj;
    enum Events
    {
        HardwareSendPacket_enum,
        HardwareReceivePacket_enum,
        SystemSleep_enum,
        SystemWakeup_enum,
        SystemShutdown_enum
    };
public:
    EventGenerator(int F):freq(F)
    {
        //type2Thread = new std::thread(&EventGenerator::generationStart, this);
    }
    void generationStart(EventManager* EventManagerObj)
    {

        for (int i=0;i<freq;i++)
        {

            int random = rand() % 5;
            switch(random)
            {
            case HardwareSendPacket_enum:
                EventObj=new HardwareSendPacket();
                EventManagerObj->postEvent(EventObj);
                cout<<EventObj->getPriority()<<endl;
                break;

            case HardwareReceivePacket_enum:
                EventObj=new HardwareReceivePacket();
                EventManagerObj->postEvent(EventObj);
                cout<<EventObj->getPriority()<<endl;
                break;

            case SystemSleep_enum:
                EventObj=new SystemSleep;
                EventManagerObj->postEvent(EventObj);
                cout<<EventObj->getPriority()<<endl;
                break;

            case SystemWakeup_enum:
                EventObj=new SystemWakeup;
                EventManagerObj->postEvent(EventObj);
                cout<<EventObj->getPriority()<<endl;
                break;

            case SystemShutdown_enum:
                EventObj=new SystemShutdown;
                EventManagerObj->postEvent(EventObj);
                cout<<EventObj->getPriority()<<endl;
                break;
            }
        }


    }

    void generationStop()
    {
        //type2Thread -> join();
        //delete type2Thread;

    }


};

int main ()
{
    EventManager& managerObj=EventManager::creatObject();
    EventGenerator generatorObj(9);
    generatorObj.generationStart(&managerObj);
    managerObj.startHandlingEvents();
    cout<<"Hello World!!";


    return 0;
}
