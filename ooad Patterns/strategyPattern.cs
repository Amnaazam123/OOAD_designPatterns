
// In strategy pattern, class behavior can be changed at run time. It is more likely polymorphism :)
// On run time, it is decided that which object will perform what?

using System;

namespace StrategyPattern
{

    class Program
    {
        public interface Strategy
        {
            public int doOperation (int num1, int num2);
        }
        public class OperationAdd : Strategy
        {
            public int doOperation(int num1, int num2)
            {
                return num1 + num2;
            }
        }
        public class OperationSubstract : Strategy
        {
            public int doOperation (int num1, int num2)
            {
                return num1 - num2;
            }
        }
        public class OperationMultiply : Strategy
        {
            public int doOperation (int num1, int num2)
            {
                return num1 * num2;
            }
        }
        public class OperationDivision : Strategy
        {
            public int doOperation (int num1, int num2)
            {
                return num1 / num2;
            }
        }
        public class Context
        {
            private Strategy strategy;

            public Context (Strategy strategy)
            {
                this.strategy = strategy;
            }

            public int executeStrategy (int num1, int num2)
            {
                return strategy.doOperation (num1, num2);
            }
        }


        static void Main(string[] args)
        {
            Context context = new Context(new OperationAdd());
            Console.WriteLine("10 + 5 = " + context.executeStrategy(10, 5));

            context = new Context(new OperationSubstract());
            Console.WriteLine("10 - 5 = " + context.executeStrategy(10, 5));

            context = new Context(new OperationMultiply());
            Console.WriteLine("10 * 5 = " + context.executeStrategy(10, 5));

            context = new Context(new OperationDivision());
            Console.WriteLine("10 / 5 = " + context.executeStrategy(10, 5));
        }

    }
}

