using Caliburn.Micro;
using System;
using System.Windows;
using WpfWnd.Views;

namespace WpfWnd.ViewModels
{
    public class WpfViewModel:Screen
    {
        #region fields
        private double _wndHeight;
        private double _wndWidth;
        private string _description;
        public delegate void SetModifiedDelegate();
        public SetModifiedDelegate OnSetModifiedDelegate = null;
        #endregion

        #region props
        public double WndHeight
        {
            get { return _wndHeight; }
            set { _wndHeight = value; NotifyOfPropertyChange(() => WndHeight); }
        }
         public double WndWidth
        {
            get { return _wndWidth; }
            set { _wndWidth = value; NotifyOfPropertyChange(() => WndWidth); }
        }

        public string Description
        {
            get { return _description; }
            set { _description = value;  NotifyOfPropertyChange(() => Description); }
        }
        #endregion


        #region ctor
        public WpfViewModel()
        {
            WndHeight = 300;
            WndWidth = 400;
            Description = "Wpf Embedded Window";
        }
        #endregion

        #region funcs
        public WpfView GetView()
        {
             System.Windows.UIElement view = null;
            WpfView retView = null;
            try
            {
                do
                {
                    view = ViewLocator.LocateForModel(this, null, null);

                    if (view == null)
                        break;
                    if (view is WpfView wpfView)
                    {
                        retView = wpfView;
                        ViewModelBinder.Bind(this, retView, null);
                    }
                        
                } while (false);
            }
            catch (Exception e)
            {
                MessageBox.Show($"WpfViewModel::GetView -  Fail to get view of Run Parameters due to exception: {e.Message}");
            }
            return retView;
        }

        public void SetData(string description)
        {
            Description = description;
        }

        public void GetData(ref string description)
        {
            description = Description;
        }

        public void OnBtnStartClicked()
        {
            Description = "Happy Day!";
        }

        public void OnBtnDoneClicked()
        {
            Description = "See you tomorrow";
            OnSetModifiedDelegate();
        }
        #endregion
    }
}
