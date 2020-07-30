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
    sealed public class WpfWndHelper
    {
        private readonly Bootstrapper _bootstrapper;
        private static readonly Lazy<WpfWndHelper> _instance = new Lazy<WpfWndHelper>(()=>new WpfWndHelper());
        public static WpfWndHelper Instance { get => _instance.Value; }
        private WpfWndHelper()
        {
            _bootstrapper = new Bootstrapper();
        }

        public WpfViewModel GetWpfVm()
        {
            WpfViewModel wpfVm = null;
            try
            {
                wpfVm = WpfWndIoC.Get<WpfViewModel>();
            }
            catch (Exception e)
            {
                MessageBox.Show($"Fail to initialize Bootstrapper due to exception {e.Message}");
            }
            return wpfVm;
        }
    }
}
