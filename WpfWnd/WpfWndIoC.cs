using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfWnd
{
    public class WpfWndIoC
    {
        public static Func<Type, string, object> GetInstance = (service, key) => { throw new InvalidOperationException("WpfWndIoC is not initialized."); };
        public static Func<Type, IEnumerable<object>> GetAllInstances = service => { throw new InvalidOperationException("WpfWndIoC is not initialized."); };
        public static Action<object> BuildUp = instance => { throw new InvalidOperationException("WpfWndIoC is not initialized."); };
        public static T Get<T>(string key = null)
        {
            return (T)GetInstance(typeof(T), key);
        }
    }
}
