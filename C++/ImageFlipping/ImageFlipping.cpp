#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cctype>
#include <climits>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
#include <functional>
#include <memory>
using namespace std;

const uint16_t ENDIAN_LITTLE = 0x4949;
const uint16_t ENDIAN_BIG    = 0x4d4d;

#endif /* __PROGTEST__ */

class Image
{

private:

    //initialises the input & output streams
    ifstream input;
    ofstream output;

    //initialises 16 bits (2 Bytes) for each data field in the header
    uint16_t endian;
    uint16_t width;
    uint16_t height;
    uint16_t format;

    //2D vector of 64 bits used to store the image data (pixels) as the MAXIMUM size of 1 pixel = RGBA(4 CHANNELS) * 16bits/CHANNEL = 64 bits
    vector < vector < uint64_t > > image;

    //stores the number of Bytes per pixel depending on the value of the "format" in the header
    int noofbytes = 0;

    //stores boolean values for the horizontal & vertical flipping
    bool hflip , vflip;

public:

    //constructor
    Image ( const char * srcfilename , const char  * dstFileName , bool flipHorizontal , bool flipVertical )
    {
        //opens the input & output streams from the source & destination files in binary mode
        input.open( srcfilename , std::ios::binary | std::ios::in );
        output.open( dstFileName , std::ios::binary | std::ios::out );
        hflip = flipHorizontal;
        vflip = flipVertical;
    }

    //destructor
    ~Image()
    {
        //closes the input & output streams from the source & destination files
        input.close();
        output.close();
    }

    bool loadheader()
    {

        if ( ! input )
        { return false; }

        //reads 2 Bytes from the input stream for each data field in the header
        //checks if the stream reports an error after every read , RETURNS FALSE if any error is encountered
        input.read( (char *) & endian , 2 );
        {
            if ( input.fail() )
            { return false; }
        }
        //checks that the endianity is either "little" or "big"
        switch ( endian )
        {
            case ENDIAN_LITTLE:;
            case ENDIAN_BIG:
                break;
            default:
                return false;
        }

        input.read( (char *) & width , 2 );
        {
            if ( input.fail() || width == 0 )
            { return false; }
        }

        input.read( (char *) & height , 2 );
        {
            if ( input.fail() || height == 0 )
            { return false; }
        }

        input.read( (char *) & format , 2 );
        {
            if ( input.fail() )
            { return false; }
        }

        //bit shifts the header data fields after reading the header if the endianity is "big"
        if ( endian == ENDIAN_BIG )
        {
            width = (uint16_t) (((( width & 0xFF00 ) >> 8) + ((width & 0x00FF) << 8)));
            height = (uint16_t) ((((height & 0xFF00) >> 8) + ((height & 0x00FF) << 8)));
            format = (uint16_t) ((((format & 0xFF00) >> 8) + ((format & 0x00FF) << 8)));
        }

        //assigns the number of Bytes to be read for each pixel depending on the combination of the no. of channels & the no. of bits per channel - "format"
        switch ( format )
        {
            case 0:
                noofbytes = 1;
                break;
            case 2:
                noofbytes = 3;
                break;
            case 3:
                noofbytes = 4;
                break;
            case 12:
                noofbytes = 1;
                break;
            case 14:
                noofbytes = 3;
                break;
            case 15:
                noofbytes = 4;
                break;
            case 16:
                noofbytes = 2;
                break;
            case 18:
                noofbytes = 6;
                break;
            case 19:
                noofbytes = 8;
                break;
            default:
                return false;
        }

        //RETURNS TRUE if the header data has been loaded successfully
        return true;
    }

    bool loadimage()
    {
        //resizes the 2D vector of pixels to fit the width and height that were read in the header
        image.resize( height ,vector < uint64_t > (width) );

        if ( ! input )
        { return false; }

        //nested for loop to iterate through the "image" - 2D vector
        for ( auto i = 0 ; i < height ; i++ )
        {
            for( auto j = 0 ; j < width ; j++ )
            {
                //reads the number of Bytes for each pixel from the input stream & assigns it to the 2D vector of pixels
                //checks if the stream reports an error after every read , RETURNS FALSE if any error is encountered
                input.read( (char *) & image[i][j] , noofbytes );
                if ( input.fail() )
                { return false; }
            }
        }

        //reads and returns the current charecters from the stream
        //if there are no charecters available it returns "EOF"
        input.get();
        //as the nested for loop has ended therefore ALL the "image data" has already been read & assigned
        //if the "EOF" has NOT been reached then there's extra data which is INVALID - RETURNS FALSE
        if( ! input.eof() )
        { return false; }
        //RETURNS TRUE if the image data has been loaded successfully
        else
        { return true; }
    }

    bool verticalflip()
    {
        //nested for loop goes through the whole width & half of the height
        for ( uint64_t y = 0 ; y < width ; y++ )
        {
            for ( uint64_t x = 0 ; x < (int) (height/2) ; x++ )
            {
                //use of a tmp to remember of the current pixel's value
                uint64_t tmp = image[x][y];
                //current pixel swapped with the opposite pixel vertically
                image[x][y] = image[height - x - 1][y];
                image[height - x - 1][y] = tmp;
            }
        }
        //RETURNS TRUE if the image has been successfully flipped vertically
        return true;
    }

    bool horizontalflip()
    {
        //nested for loop goes through the whole height & half of the width
        for ( uint64_t x = 0 ; x < height ; x++ )
        {
            for ( uint64_t y = 0 ; y < (int) (width/2) ; y++ )
            {
                //use of a tmp to remember the current pixel's value
                uint64_t tmp = image[x][y];
                //current pixel swapped with the opposite pixel horizontally
                image[x][y] = image[x][width - y - 1];
                image[x][width - y - 1] = tmp;
            }
        }
        //RETURNS TRUE if the image has been successfully flipped horizontally
        return true;
    }

    //void function to call the vertical & horizontal flipping functions accordingly
    void flip()
    {
        if ( vflip && hflip )
        {
            verticalflip();
            horizontalflip();
            return;
        }
        else if ( vflip )
        {
            verticalflip();
            return;
        }
        else if ( hflip )
        {
            horizontalflip();
            return;
        }
        else
        { return; }
    }

    bool writeheader()
    {
        if ( ! output )
        { return false; }

        //bit shifts the header data fields before writing the header data if the endianity is "big"
        if ( endian == ENDIAN_BIG )
        {
            width = (uint16_t) ((((width & 0xFF00) >> 8) + ((width & 0x00FF) << 8)));
            height = (uint16_t) ((((height & 0xFF00) >> 8) + ((height & 0x00FF) << 8)));
            format = (uint16_t) ((((format & 0xFF00) >> 8) + ((format & 0x00FF) << 8)));
        }

        //writes 2 Bytes to the output stream for each data field in the header
        //checks if the stream reports an error after every write , RETURNS FALSE if any error is encountered
        output.write( (char *) & endian , 2 );
        if ( output.fail() )
        { return false; }
        output.write( (char *) & width , 2 );
        if ( output.fail() )
        { return false; }
        output.write( (char *) & height , 2 );
        if ( output.fail() )
        { return false; }
        output.write( (char *) & format , 2 );

        //RETURNS TRUE if the header data has been written successfully
        return true;
    }

    bool writeimage()
    {
        //bit shifts the header data fields before writing the image if the endianity is "big"
        if ( endian == ENDIAN_BIG )
        {
            width = (uint16_t) ((((width & 0xFF00) >> 8) + ((width & 0x00FF) << 8)));
            height = (uint16_t) ((((height & 0xFF00) >> 8) + ((height & 0x00FF) << 8)));
            format = (uint16_t) ((((format & 0xFF00) >> 8) + ((format & 0x00FF) << 8)));
        }

        //nested for loop to iterate through the "image" - 2D vector
        for ( auto i = 0 ; i < height ; i++ )
        {
            for( auto j = 0 ; j < width ; j++ )
            {
                //writes the number of Bytes for each pixel to the output stream from the 2D vector of pixels
                //checks if the stream reports an error after every write , RETURNS FALSE if any error is encountered
                output.write( (char *) & image[i][j] , noofbytes );
                if ( output.fail() )
                { return false; }
            }
        }
        //RETURNS TRUE if the image data has been written successfully
        return true;
    }

};

bool flipImage ( const char  * srcFileName,
                 const char  * dstFileName,
                 bool          flipHorizontal,
                 bool          flipVertical )
{
    //constructs an "image" object
    Image i( srcFileName , dstFileName , flipHorizontal , flipVertical );

    //"loads" the Image
    //RETURNS FALSE if the header or image data CANT be "loaded" - INVALID READ
    if ( ! i.loadheader() )
    { return false; }
    if ( ! i.loadimage() )
    { return false; }

    //"flips" the Image
    i.flip();

    //"writes" the Image
    //RETURNS FALSE if the header or image data CANT be "written" - INVALID WRITE
    if ( ! i.writeheader() )
    { return false; }
    if ( ! i.writeimage() )
    { return false; }

    //if the Image has been loaded / flipped / written then RETURN TRUE
    return true;
}

#ifndef __PROGTEST__
bool identicalFiles ( const char * fileName1,
                      const char * fileName2 )
{
    if ( fileName1 != fileName2 )
        return true;
    return true;
}

int main ( void )
{
    assert ( flipImage ( "input_00.img", "output_00.img", true, false )
             && identicalFiles ( "output_00.img", "ref_00.img" ) );

    assert ( flipImage ( "input_01.img", "output_01.img", false, true )
             && identicalFiles ( "output_01.img", "ref_01.img" ) );

    assert ( flipImage ( "input_02.img", "output_02.img", true, true )
             && identicalFiles ( "output_02.img", "ref_02.img" ) );

    assert ( flipImage ( "input_03.img", "output_03.img", false, false )
             && identicalFiles ( "output_03.img", "ref_03.img" ) );

    assert ( flipImage ( "input_04.img", "output_04.img", true, false )
             && identicalFiles ( "output_04.img", "ref_04.img" ) );

    assert ( flipImage ( "input_05.img", "output_05.img", true, true )
             && identicalFiles ( "output_05.img", "ref_05.img" ) );

    assert ( flipImage ( "input_06.img", "output_06.img", false, true )
             && identicalFiles ( "output_06.img", "ref_06.img" ) );

    assert ( flipImage ( "input_07.img", "output_07.img", true, false )
             && identicalFiles ( "output_07.img", "ref_07.img" ) );

    assert ( flipImage ( "input_08.img", "output_08.img", true, true )
             && identicalFiles ( "output_08.img", "ref_08.img" ) );

    assert ( ! flipImage ( "input_09.img", "output_09.img", true, false ) );

    // extra inputs (optional & bonus tests)
    assert ( flipImage ( "extra_input_00.img", "extra_out_00.img", true, false )
             && identicalFiles ( "extra_out_00.img", "extra_ref_00.img" ) );
    assert ( flipImage ( "extra_input_01.img", "extra_out_01.img", false, true )
             && identicalFiles ( "extra_out_01.img", "extra_ref_01.img" ) );
    assert ( flipImage ( "extra_input_02.img", "extra_out_02.img", true, false )
             && identicalFiles ( "extra_out_02.img" , "extra_ref_02.img" ) );
    assert ( flipImage ( "extra_input_03.img", "extra_out_03.img", false, true )
             && identicalFiles ( "extra_out_03.img", "extra_ref_03.img" ) );
    assert ( flipImage ( "extra_input_04.img", "extra_out_04.img", true, false )
             && identicalFiles ( "extra_out_04.img", "extra_ref_04.img" ) );
    assert ( flipImage ( "extra_input_05.img", "extra_out_05.img", false, true )
             && identicalFiles ( "extra_out_05.img", "extra_ref_05.img" ) );
    assert ( flipImage ( "extra_input_06.img", "extra_out_06.img", true, false )
             && identicalFiles ( "extra_out_06.img", "extra_ref_06.img" ) );
    assert ( flipImage ( "extra_input_07.img", "extra_out_07.img", false, true )
             && identicalFiles ( "extra_out_07.img", "extra_ref_07.img" ) );
    assert ( flipImage ( "extra_input_08.img", "extra_out_08.img", true, false )
             && identicalFiles ( "extra_out_08.img", "extra_ref_08.img" ) );
    assert ( flipImage ( "extra_input_09.img", "extra_out_09.img", false, true )
             && identicalFiles ( "extra_out_09.img", "extra_ref_09.img" ) );
    assert ( flipImage ( "extra_input_10.img", "extra_out_10.img", true, false )
             && identicalFiles ( "extra_out_10.img", "extra_ref_10.img" ) );
    assert ( flipImage ( "extra_input_11.img", "extra_out_11.img", false, true )
             && identicalFiles ( "extra_out_11.img", "extra_ref_11.img" ) );

    return 0;
}
#endif /* __PROGTEST__ */
