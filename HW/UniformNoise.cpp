// UniformNoise
#include "items.h"

void UniformNoise()
{
    cv::Mat m_original = cv::imread("images//dpi_hw04.bmp", 0);
    int ROW = m_original.rows;
    int COL = m_original.cols;
    srand(time(NULL));
    cv::Mat m_un, m_after;
    m_un.create(ROW, COL, CV_8UC1);
    m_after.create(ROW, COL, CV_8UC1);

    //-----------------------------------------------------------Add [Uniform Noise] in range [-10, +10]
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++)
        {
            int tp, rd = my_random(-10, 10); //[min , max]
            tp = m_original.at<uchar>(r, c) + rd;
            if (tp < 0)
                tp = 0;
            else if (tp > 255)
                tp = 255;
            m_un.at<uchar>(r, c) = tp;
        }
    myHist *pHist = new myHist(myHist::Type::Image);

    //------------------------------------------------------------------------------------------
    int Smax = 7;
    for (int r = 1; r < ROW - 1; r++)
    {
        for (int c = 1; c < COL - 1; c++)
        {
            bool b = false, Zxy = m_un.at<uchar>(r, c);
            //------------------------------------------------------------------------------------------
            for (int s = 3; s <= Smax; s += 2)
            { //----------------------
                int s2 = s * s, viot = 0;
                int *arr = new int[s2];
                for (int i = -(s >> 1); i <= s >> 1; i++)
                {
                    for (int j = -(s >> 1); j <= s >> 1; j++)
                    {
                        if (r + i < 0 || r + i == ROW || c + j < 0 || c + j == COL)
                        {
                            b = true;
                            break;
                        }
                        arr[viot] = m_un.at<uchar>(r + i, c + j);
                        viot++;
                    }
                    if (b)
                    {
                        break;
                    }
                }
                if (b || ((s2) != viot))
                {
                    break;
                }
                QuickSort(arr, 0, viot - 1);
                int A1 = arr[viot >> 1] - arr[0],
                    A2 = arr[viot >> 1] - arr[viot - 1];
                //------------------------------------------------------------------------------------------
                if (A1 > 0 && A2 < 0)
                {
                    int B1 = Zxy - arr[0],
                        B2 = Zxy - arr[viot - 1];
                    if (B1 > 0 && B2 < 0)
                    {
                        m_after.at<uchar>(r, c) = Zxy;
                    }
                    else
                    {
                        m_after.at<uchar>(r, c) = arr[viot >> 1];
                    }
                }
                else if (s == Smax)
                {
                    m_after.at<uchar>(r, c) = Zxy;
                }
                //------------------------------------------------------------------------------------------
                delete[] arr;
            }
        }
    }
    //------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    cv::imshow("original", m_original);

    pHist->CalcHist(m_original);
    m_original = cv::Scalar::all(0);
    pHist->Show(m_original);
    cv::namedWindow("original hist", cv::WINDOW_AUTOSIZE);
    cv::imshow("original hist", m_original);
    pHist->Clear();

    //------------------------------------------------------------------------------------------
    cv::namedWindow("Add Uniform Noise", cv::WINDOW_AUTOSIZE);
    cv::imshow("Add Uniform Noise", m_un);

    pHist->CalcHist(m_un);
    m_un = cv::Scalar::all(0);
    pHist->Show(m_un);
    cv::namedWindow("Add Uniform Noise hist", cv::WINDOW_AUTOSIZE);
    cv::imshow("Add Uniform Noise hist", m_un);
    pHist->Clear();

    //------------------------------------------------------------------------------------------
    cv::namedWindow("After", cv::WINDOW_AUTOSIZE);
    cv::imshow("After", m_after);

    pHist->CalcHist(m_after);
    m_after = cv::Scalar::all(0);
    pHist->Show(m_after);
    cv::namedWindow("After hist", cv::WINDOW_AUTOSIZE);
    cv::imshow("After hist", m_after);
    pHist->Clear();

    cv::waitKey(0);
}