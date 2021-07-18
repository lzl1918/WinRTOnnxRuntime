using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

using WinRTOnnxRuntime;

namespace UWPAppSample
{
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            var tensor = new FloatTensor(new long[] { 1 }, new float[] { 4 });
            using var runtime = OnnxRuntime.Create();
            using var session = runtime.LoadSession("path/to/your/model");
        }
    }
}
