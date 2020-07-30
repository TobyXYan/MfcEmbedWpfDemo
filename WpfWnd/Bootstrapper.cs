using Caliburn.Micro;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using WpfWnd.ViewModels;

namespace WpfWnd
{
    class Bootstrapper:BootstrapperBase
    {
         #region fields
        protected readonly SimpleContainer Container = new SimpleContainer();
        #endregion

        #region ctor
        public Bootstrapper():base(false)
        {
            
            Initialize();
            WpfWndIoC.GetInstance     = GetInstance;
            WpfWndIoC.GetAllInstances = GetAllInstances;
            WpfWndIoC.BuildUp         = BuildUp;
            Configure();
        }
        #endregion

        #region funcs
        protected new void Configure()
        {
            Container.Singleton<IWindowManager, WindowManager>();
            Container.PerRequest<WpfViewModel>();
        }

        protected new object GetInstance(Type service, string key)
        {
            return Container.GetInstance(service, key);
        }

        protected new IEnumerable<object> GetAllInstances(Type service)
        {
            return Container.GetAllInstances(service);
        }

        protected new void BuildUp(object instance)
        {
            Container.BuildUp(instance);
        }
        #endregion
    }
}
