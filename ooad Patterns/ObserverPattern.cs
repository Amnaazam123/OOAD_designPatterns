using Observerpattern;
using System;
using System.Collections.Generic;

namespace Observerpattern
{
    abstract class Observer
    {
        protected Subject subject;       //each observer will have its state and its observer count(not necesarry).
        public abstract void update();
    }

    class Subject
    {

        private List<Observer> observers = new List<Observer>();           //observers jin ko notify krna hai
        private int state;          //jis cheez se observers ko update krna hai

        public int getState()
        {
            return state;
        }

        public void setState(int state)
        {
            this.state = state;
            notifyAllObservers();
        }



        public void attach(Observer observer)
        {
            observers.Add(observer);
        }

        public void notifyAllObservers()
        {
            foreach (Observer observer in observers)
            {
                observer.update();
            }
        }
    }

    class BinaryObserver : Observer
    {

        public BinaryObserver(Subject subject)
        {
            this.subject = subject;
            this.subject.attach(this);
        }

        public override void update()
        {
            Console.WriteLine("Binary String: ");
        }
    }
}

class Program
    {
    static void Main(string[] args)
    {
        Subject subject = new Subject();

        new BinaryObserver(subject);
        subject.setState(15);
    }
}
    

