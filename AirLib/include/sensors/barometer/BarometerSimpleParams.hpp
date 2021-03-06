// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef msr_airlib_BarometerSimpleParams_hpp
#define msr_airlib_BarometerSimpleParams_hpp

#include "common/Common.hpp"


namespace msr { namespace airlib {


struct BarometerSimpleParams {
    //user specified sea level pressure 
    real_T qnh = EarthUtils::SeaLevelPressure / 100.0f; // hPa

    //sea level min,avh,max = 950,1013,1050 ie approx 3.65% variation
    //regular pressure changes in quiet conditions are 1/10th of this
    //Mariner's Pressure Atlas, David Burch, 2014
    //https://www.starpath.com/ebooksamples/9780914025382_sample.pdf
    real_T pressure_factor_sigma = 0.0365f / 2 / 10;
    real_T pressure_factor_tau = 3600;

    /*
    Ref: A Stochastic Approach to Noise Modeling for Barometric Altimeters
         Angelo Maria Sabatini* and Vincenzo Genovese
         Sample values are from Table 1
         https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3871085/
         This is however not used because numbers mentioned in paper doesn't match experiments.

         real_T correlated_noise_sigma = 0.27f;
         real_T correlated_noise_tau = 0.87f;
         real_T unnorrelated_noise_sigma = 0.24f;
    */

    //Experiments for MEAS MS56112 sensor shows 0.021mbar, datasheet has resoultion of 0.027mbar @ 1024
    //http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=MS5611-01BA03&DocType=Data+Sheet&DocLang=English
    real_T unnorrelated_noise_sigma = 0.027f * 100;

};


}} //namespace
#endif
