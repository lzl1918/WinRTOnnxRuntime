using WinRTOnnxRuntime;

namespace ConsoleAppSample
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            var tensor = new FloatTensor(new long[] { 1 }, new float[] { 4 });
            using var runtime = OnnxRuntime.Create();
            using var session = runtime.LoadSession("path/to/your/model");
        }
    }
}
