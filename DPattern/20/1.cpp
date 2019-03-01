#include<iostream>

using namespace std;
typedef int Topic;
const Topic  NO_HELP_TOPIC = -1;

class HelpHandler
{
  private:
    HelpHandler* _successor;
    Topic _topic;
  public:
    HelpHandler(HelpHandler* h = 0, Topic t = NO_HELP_TOPIC):
       _successor(h), _topic(t) {}
    virtual bool HasHelp()
    {
      return _topic != NO_HELP_TOPIC;
    }
    virtual void SetHandler(HelpHandler* h, Topic t)
    {
      this -> _topic = t;   //将特殊topic设置到当前组件中, 忽略传入的组件
    }
    virtual void HandleHelp()
    {
      if (_successor != 0)
      {
        _successor -> HandleHelp();
      }
    }
};

class Widget : public HelpHandler
{
  private:
    Widget* _parent;
  protected:
    Widget(Widget* parent, Topic t = NO_HELP_TOPIC):
      HelpHandler(parent, t) 
    {
      _parent = parent;
    }
};

class Button : public Widget
{
  public:
    Button(Widget* d, Topic t = NO_HELP_TOPIC):
      Widget(d, t) {}
    virtual void HandleHelp()
    {
      if (HasHelp())
      {
        cout << "offer help on the button" << endl;
      }
      else
      {
        HelpHandler::HandleHelp();
      }
    }
};

class Dialog : public Widget 
{
  public:
    Dialog(HelpHandler* h, Topic t = NO_HELP_TOPIC):
        Widget(0)   //表示dialog类型没有父类窗口，传入的HelphHandler组件不用考虑
    {
      SetHandler(h, t);  //表示将当前的组件topic设置为传入的组件的主题。
    }
    virtual void HandleHelp ()
    {
      if (HasHelp())
      {
        cout << "offer help on the dialog" << endl;
      }
      else
      {
        cout << "dialog no help" << endl;
        HelpHandler::HandleHelp();
      }
    }
};

class Application:public HelpHandler
{
  public:
    Application(Topic t): HelpHandler(0, t) {}
    virtual void HandleHelp()
    {
      cout << "offer help on the application" << endl;
    }
};
int main()
{
 const Topic PRINT_TOPIC = 1;
 const Topic PAPER_ORIENTATION_TOPIC = 2;
 const Topic APPLICATION_TOPIC = 3;

 Application* application = new Application(APPLICATION_TOPIC);
 application -> HandleHelp();
 Dialog* dialog = new Dialog(application, PRINT_TOPIC);
 dialog -> HandleHelp();
 Button* button = new Button(dialog, PAPER_ORIENTATION_TOPIC);
 button -> HandleHelp();
  return 0;
}
