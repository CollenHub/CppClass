using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpeContrast
{
    public class ListTest<T,R>
    {
        public T Tp { get; set; }

        public R Rp { get; set; }
        public ListTest(T t,R r)
        {
            Tp = t;
            Rp = r;
        }
    }
    public class Test
    {
        void Testx()
        {
            var x = new ListTest<Base1st,Base2nd>(new derived1st(), new Derived2nd());
        }
    }
}
