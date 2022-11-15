public class Main
{
    public static void main(String[] args){
        Set set1 = new Set(new double[] {3, 13});
        Set set2 = new Set(set1.set);
        System.out.print("set1 and set2 после создания (set2 создан на основе set1):\n");
        set1.Print();
        set2.Print();

        System.out.print("set2.DeleteElement(3):\n   ");
        set2.DeleteElement(3);
        set2.Print();

        System.out.print("set2.AddElement(32):\n   ");
        set2.AddElement(32);
        set2.Print();

        System.out.print("set2.AddElement(3):\n   ");
        set2.AddElement(3);

        System.out.print("set1.Equals(set2):\n   ");
        System.out.println(set1.Equals(set2));

        System.out.print("set3 = set1.combineSet(set2):\n   ");
        Set set3 = set1.CombineSet(set2);
        set3.Print();

        System.out.print("set1.ToString():\n   ");
        System.out.println(set1.ToString());
    }
    public static class Set
    {
        public double[] set;

        public Set(int N)
        {
            this.set = new double[N];
            for (int i = 0; i < N; i++)
                this.set[i] = -1;
        }

        public Set(double[] set)
        {
            this.set = new double[set.length];
            for (int i = 0; i < set.length; i++)
                this.set[i] = set[i];
        }

        public Set CombineSet(Set addedSet)
        {
            int size = 0;
            for(double i : this.set){
                size++;
            }
            for(double i : addedSet.set){
                size++;
            }

            Set combineSet = new Set(size);

            for(int i = 0; i < this.set.length; i++)
            {
                if (this.set[i] != -1)
                {
                    combineSet.AddElement(this.set[i]);
                }
            }

            for (int i = 0; i < addedSet.set.length; i++)
            {
                if (addedSet.set[i] != -1)
                {
                            combineSet.AddElement(addedSet.set[i]);
                }
            }

            combineSet.set = Sort(combineSet.set);

            return combineSet;
        }

        public void Print()
        {
            System.out.print("Set: ");
            for(int i = 0; i < this.set.length; i++)
            {
                if (this.set[i] != -1)
                {
                    System.out.print(this.set[i] + "; ");
                }
            }

            System.out.println();
        }

        public void AddElement(double element)
        {
            if(!this.IsSetElement(element))
            {
                for(int i = 0; i < this.set.length; i++)
                {
                    if(this.set[i] == -1)
                    {
                        this.set[i] = element;
                        Sort(this.set);
                        return;
                    }
                }

                System.out.println("Множество заполнено. Невозможно добавить элемент");
            }
        }

        public void DeleteElement(double element)
        {
            if(this.IsSetElement(element))
            {
                for(int i = 0; i < this.set.length; i++)
                {
                    if (this.set[i] == element)
                    {
                        this.set[i] = -1;
                        break;
                    }

                }

                Sort(this.set);
            }
            else {System.out.print("Нет такого элемента");}
        }

        public boolean Equals(Set comparableSet)
        {
            if (this.set.length != comparableSet.set.length)
                return false;

            for (int i = 0; i < this.set.length; i++)
                if (this.set[i] != comparableSet.set[i])
                    return false;

            return true;
        }

        public String ToString(){
            String result = "";
            for(double x : this.set) {
                result += x + " ";
            }
            return "Set: " + result;
        }

        private boolean IsSetElement(double element)
        {
            for (double x : this.set){
                if (x == element){
                    return true;
                }
            }
            return false;
        }

        private double[] Sort(double[] set)
        {
            double temp;

            for(int i = 0; i < set.length - 1; i++)
            {
                for (int j = i + 1; j < set.length; j++)
                {
                    if(set[i] > set[j])
                    {
                        temp = set[i];
                        set[i] = set[j];
                        set[j] = temp;
                    }
                }
            }

            return set;
        }
    }
}
