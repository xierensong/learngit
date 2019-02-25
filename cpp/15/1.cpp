#include<iostream>

using namespace std;

class User
{
  private:
    string name;
    string address;
    string city;
    string province;
    string ZIPcode;
  public:
    User(string myName, string myAddress, string myCity, string myProvince, string myZIPcode):
      name(myName), address(myAddress), city(myCity), province(myProvince), ZIPcode(myZIPcode) {}
    string getAddress()
    {
        return  this -> address;
    }
};

class Package 
{
  private:
    User sender;
    User recipient;
    double weight;
    double cost_per_ounce;
 public:
    Package(User mySender, User myRecipient, 
        double myWeight, double myCost_per_ounce
    ):
      sender(mySender), recipient(myRecipient),
      weight(myWeight), cost_per_ounce(myCost_per_ounce)
   {}
    
    string getSenderAddress()
    {
      return sender.getAddress();
    }
    string getRecipientAddress()
    {
      return recipient.getAddress();
    }
    double getWeight()
    {
      return this -> weight;
    }
    virtual double calculateCost()
    {
      return weight * cost_per_ounce;
    }
};

class TwoDayPackage : public Package
{
  private:
    double flat_fee;
  public:
    TwoDayPackage(User mySender, User myRecipient, 
        double myWeight, double myCost_per_ounce,
        double myFlat_fee):
    Package(mySender, myRecipient, myWeight, myCost_per_ounce),
    flat_fee(myFlat_fee) {}

    virtual double calculateCost()
    {
      double base_fee = Package::calculateCost();
      return base_fee + flat_fee;
    }
};

class OvernightPackage : public Package
{
  private:
    double additional_fee_per_ounce;
  public:
    OvernightPackage(User mySender, User myRecipient,
        double myWeight, double myCost_per_ounce,
        double myAdditional_fee_per_ounce):
      Package(mySender,myRecipient, myWeight, myCost_per_ounce),
      additional_fee_per_ounce(myAdditional_fee_per_ounce) {}

    virtual double calculateCost()
    {
      double base_fee = Package::calculateCost();
      return base_fee + Package::getWeight() * additional_fee_per_ounce;
    }
};

void process(Package* myPackage)
{
    string sender_address = myPackage -> getSenderAddress();
    string recipient_address = myPackage -> getRecipientAddress();
    cout << "sender address:" << sender_address << endl;
    cout << "recipient address:" << recipient_address << endl;
    double cost = myPackage -> calculateCost();
    cout << "the total cost:" << cost << endl;
}

int main()
{
  User* sender1 = new User("Jim", "BEI JING road", "BeiJing", "BeiJing","210000");
  User* recipient1 = new User("Tom", "NAN JING road", "NanJing", "JiangSu", "280000");
  //Package* package1 = new Package(*sender1, *recipient1, 50.0, 3.5);
  OvernightPackage* overnightPackage1 = new OvernightPackage(*sender1, *recipient1, 50.0, 3.5, 1);
  process(overnightPackage1);
  TwoDayPackage* twoDayPackage1 = new TwoDayPackage(*sender1, *recipient1, 50.0, 3.5, 2);
  process(twoDayPackage1);
  return 0;
}
