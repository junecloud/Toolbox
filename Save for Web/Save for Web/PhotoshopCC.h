/*
 * PhotoshopCC.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class PhotoshopCCApplication, PhotoshopCCDocument, PhotoshopCCBatchOptions, PhotoshopCCChangeModeOptions, PhotoshopCCBitmapModeOptions, PhotoshopCCChannel, PhotoshopCCColorSampler, PhotoshopCCContactSheetOptions, PhotoshopCCCountItem, PhotoshopCCFont, PhotoshopCCGalleryBannerOptions, PhotoshopCCGalleryColorOptions, PhotoshopCCGalleryImagesOptions, PhotoshopCCGalleryOptions, PhotoshopCCGallerySecurityOptions, PhotoshopCCGalleryThumbnailOptions, PhotoshopCCHistoryState, PhotoshopCCIndexedModeOptions, PhotoshopCCInfoObject, PhotoshopCCLayer, PhotoshopCCArtLayer, PhotoshopCCLayerComp, PhotoshopCCLayerSet, PhotoshopCCMeasurementScale, PhotoshopCCPicturePackageOptions, PhotoshopCCPresentationOptions, PhotoshopCCSelectionObject, PhotoshopCCSettingsObject, PhotoshopCCTextObject, PhotoshopCCXMPMetadata, PhotoshopCCOpenOptions, PhotoshopCCCameraRAWOpenOptions, PhotoshopCCDICOMOpenOptions, PhotoshopCCEPSOpenOptions, PhotoshopCCPDFOpenOptions, PhotoshopCCPhotoCDOpenOptions, PhotoshopCCRawFormatOpenOptions, PhotoshopCCSaveOptions, PhotoshopCCBMPSaveOptions, PhotoshopCCEPSSaveOptions, PhotoshopCCGIFSaveOptions, PhotoshopCCJPEGSaveOptions, PhotoshopCCPDFSaveOptions, PhotoshopCCPhotoshopDCS10SaveOptions, PhotoshopCCPhotoshopDCS20SaveOptions, PhotoshopCCPhotoshopSaveOptions, PhotoshopCCPICTFileSaveOptions, PhotoshopCCPICTResourceSaveOptions, PhotoshopCCPixarSaveOptions, PhotoshopCCPNGSaveOptions, PhotoshopCCRawSaveOptions, PhotoshopCCSGIRGBSaveOptions, PhotoshopCCTargaSaveOptions, PhotoshopCCTIFFSaveOptions, PhotoshopCCExportOptions, PhotoshopCCIllustratorPathsExportOptions, PhotoshopCCSaveForWebExportOptions, PhotoshopCCFilterOptions, PhotoshopCCAddNoise, PhotoshopCCAverage, PhotoshopCCBlur, PhotoshopCCBlurMore, PhotoshopCCClouds, PhotoshopCCCustomFilter, PhotoshopCCDeinterlace, PhotoshopCCDespeckle, PhotoshopCCDifferenceClouds, PhotoshopCCDiffuseGlow, PhotoshopCCDisplaceFilter, PhotoshopCCDustAndScratches, PhotoshopCCGaussianBlur, PhotoshopCCGlassFilter, PhotoshopCCHighPass, PhotoshopCCLensBlur, PhotoshopCCLensFlare, PhotoshopCCMaximumFilter, PhotoshopCCMedianNoise, PhotoshopCCMinimumFilter, PhotoshopCCMotionBlur, PhotoshopCCNTSCColors, PhotoshopCCOceanRipple, PhotoshopCCOffsetFilter, PhotoshopCCPinch, PhotoshopCCPolarCoordinates, PhotoshopCCRadialBlur, PhotoshopCCRipple, PhotoshopCCSharpen, PhotoshopCCSharpenEdges, PhotoshopCCSharpenMore, PhotoshopCCShear, PhotoshopCCSmartBlur, PhotoshopCCSpherize, PhotoshopCCTextureFill, PhotoshopCCTwirl, PhotoshopCCUnsharpMask, PhotoshopCCWaveFilter, PhotoshopCCZigzag, PhotoshopCCAdjustmentOptions, PhotoshopCCAutomaticContrast, PhotoshopCCAutomaticLevels, PhotoshopCCBrightnessAndContrast, PhotoshopCCColorBalance, PhotoshopCCCurves, PhotoshopCCDesaturate, PhotoshopCCEqualize, PhotoshopCCInversion, PhotoshopCCLevelsAdjustment, PhotoshopCCMixChannels, PhotoshopCCPhotoFilter, PhotoshopCCPosterize, PhotoshopCCSelectiveColor, PhotoshopCCShadowHighlight, PhotoshopCCThresholdAdjustment, PhotoshopCCColorValue, PhotoshopCCCMYKColor, PhotoshopCCGrayColor, PhotoshopCCHSBColor, PhotoshopCCLabColor, PhotoshopCCNoColor, PhotoshopCCRGBColor, PhotoshopCCRGBHexColor, PhotoshopCCPathItem, PhotoshopCCPathPoint, PhotoshopCCPathPointInfo, PhotoshopCCSubPathInfo, PhotoshopCCSubPathItem, PhotoshopCCNotifier, PhotoshopCCMillimeters, PhotoshopCCPoints, PhotoshopCCPicas, PhotoshopCCTraditionalPoints, PhotoshopCCTraditionalPicas, PhotoshopCCCiceros, PhotoshopCCPercent, PhotoshopCCPixels, PhotoshopCCRealOrLengthUnit, PhotoshopCCRealOrLengthOrPixelUnit, PhotoshopCCRealOrLengthPixelOrPercentUnit;

enum PhotoshopCCDbex {
	PhotoshopCCDbexNeverShowDebugger = 'hnsd' /* never show debugger */,
	PhotoshopCCDbexShowOnError = 'hdoe' /* show on error */,
	PhotoshopCCDbexShowBeforeRunning = 'hbr ' /* show before running */
};
typedef enum PhotoshopCCDbex PhotoshopCCDbex;

enum PhotoshopCCE815 {
	PhotoshopCCE815Eight = 'Eigt',
	PhotoshopCCE815One = 'One ',
	PhotoshopCCE815Sixteen = 'STen',
	PhotoshopCCE815ThirtyTwo = 'Tty2'
};
typedef enum PhotoshopCCE815 PhotoshopCCE815;

enum PhotoshopCCOpAs {
	PhotoshopCCOpAsAliasPIX = 'e025',
	PhotoshopCCOpAsBMP = 'e002',
	PhotoshopCCOpAsCameraRAW = 'e032',
	PhotoshopCCOpAsCompuServeGIF = 'e003',
	PhotoshopCCOpAsDICOM = 'e033',
	PhotoshopCCOpAsElectricImage = 'e026',
	PhotoshopCCOpAsEPS = 'e022',
	PhotoshopCCOpAsEPSPICTPreview = 'e023',
	PhotoshopCCOpAsEPSTIFFPreview = 'e024',
	PhotoshopCCOpAsFilmstrip = 'e005',
	PhotoshopCCOpAsJPEG = 'e006',
	PhotoshopCCOpAsPCX = 'e007',
	PhotoshopCCOpAsPDF = 'e021',
	PhotoshopCCOpAsPhotoCD = 'e009',
	PhotoshopCCOpAsPhotoshopDCS10 = 'e018',
	PhotoshopCCOpAsPhotoshopDCS20 = 'e019',
	PhotoshopCCOpAsPhotoshopEPS = 'e004',
	PhotoshopCCOpAsPhotoshopFormat = 'e000',
	PhotoshopCCOpAsPhotoshopPDF = 'e008',
	PhotoshopCCOpAsPICTFile = 'e010',
	PhotoshopCCOpAsPICTResource = 'e011',
	PhotoshopCCOpAsPixar = 'e012',
	PhotoshopCCOpAsPNG = 'e013',
	PhotoshopCCOpAsPortableBitmap = 'e027',
	PhotoshopCCOpAsRaw = 'e014',
	PhotoshopCCOpAsScitexCT = 'e015',
	PhotoshopCCOpAsSGIRGB = 'e029',
	PhotoshopCCOpAsSoftImage = 'e030',
	PhotoshopCCOpAsTarga = 'e016',
	PhotoshopCCOpAsTIFF = 'e017',
	PhotoshopCCOpAsWavefrontRLA = 'e028',
	PhotoshopCCOpAsWirelessBitmap = 'e031'
};
typedef enum PhotoshopCCOpAs PhotoshopCCOpAs;

enum PhotoshopCCSvFm {
	PhotoshopCCSvFmAliasPIX = 'e025',
	PhotoshopCCSvFmBMP = 'e002',
	PhotoshopCCSvFmCompuServeGIF = 'e003',
	PhotoshopCCSvFmElectricImage = 'e026',
	PhotoshopCCSvFmJPEG = 'e006',
	PhotoshopCCSvFmPCX = 'e007',
	PhotoshopCCSvFmPhotoshopDCS10 = 'e018',
	PhotoshopCCSvFmPhotoshopDCS20 = 'e019',
	PhotoshopCCSvFmPhotoshopEPS = 'e004',
	PhotoshopCCSvFmPhotoshopFormat = 'e000',
	PhotoshopCCSvFmPhotoshopPDF = 'e008',
	PhotoshopCCSvFmPICTFile = 'e010',
	PhotoshopCCSvFmPICTResource = 'e011',
	PhotoshopCCSvFmPixar = 'e012',
	PhotoshopCCSvFmPNG = 'e013',
	PhotoshopCCSvFmPortableBitmap = 'e027',
	PhotoshopCCSvFmRaw = 'e014',
	PhotoshopCCSvFmScitexCT = 'e015',
	PhotoshopCCSvFmSGIRGB = 'e029',
	PhotoshopCCSvFmSoftImage = 'e030',
	PhotoshopCCSvFmTarga = 'e016',
	PhotoshopCCSvFmTIFF = 'e017',
	PhotoshopCCSvFmWavefrontRLA = 'e028',
	PhotoshopCCSvFmWirelessBitmap = 'e031'
};
typedef enum PhotoshopCCSvFm PhotoshopCCSvFm;

enum PhotoshopCCSavo {
	PhotoshopCCSavoAsk = 'ask ',
	PhotoshopCCSavoNo = 'no  ',
	PhotoshopCCSavoYes = 'yes '
};
typedef enum PhotoshopCCSavo PhotoshopCCSavo;

enum PhotoshopCCE050 {
	PhotoshopCCE050Always = 'e051',
	PhotoshopCCE050ErrorDialogs = 'e052',
	PhotoshopCCE050Never = 'Nevr'
};
typedef enum PhotoshopCCE050 PhotoshopCCE050;

enum PhotoshopCCE080 {
	PhotoshopCCE080Bitmap = 'e085',
	PhotoshopCCE080CMYK = 'e083',
	PhotoshopCCE080Duotone = 'e088',
	PhotoshopCCE080Grayscale = 'e081',
	PhotoshopCCE080IndexedColor = 'e086',
	PhotoshopCCE080Lab = 'e084',
	PhotoshopCCE080Multichannel = 'e087',
	PhotoshopCCE080RGB = 'e082'
};
typedef enum PhotoshopCCE080 PhotoshopCCE080;

enum PhotoshopCCE089 {
	PhotoshopCCE089Bitmap = 'e085',
	PhotoshopCCE089CMYK = 'e083',
	PhotoshopCCE089Grayscale = 'e081',
	PhotoshopCCE089IndexedColor = 'e086',
	PhotoshopCCE089Lab = 'e084',
	PhotoshopCCE089Multichannel = 'e087',
	PhotoshopCCE089RGB = 'e082'
};
typedef enum PhotoshopCCE089 PhotoshopCCE089;

enum PhotoshopCCE090 {
	PhotoshopCCE090Custom = 'e092',
	PhotoshopCCE090None = 'DNne',
	PhotoshopCCE090Working = 'e091'
};
typedef enum PhotoshopCCE090 PhotoshopCCE090;

enum PhotoshopCCE110 {
	PhotoshopCCE110Transparent = 'e113',
	PhotoshopCCE110UseBackgroundColor = 'e112',
	PhotoshopCCE110White = 'e111'
};
typedef enum PhotoshopCCE110 PhotoshopCCE110;

enum PhotoshopCCE100 {
	PhotoshopCCE100Four = 'Four',
	PhotoshopCCE100High = 'e107',
	PhotoshopCCE100Low = 'e101',
	PhotoshopCCE100None = 'DNne',
	PhotoshopCCE100Normal = 'Nrml',
	PhotoshopCCE100Seven = 'e106',
	PhotoshopCCE100Six = 'e105',
	PhotoshopCCE100Three = 'e103',
	PhotoshopCCE100Two = 'Two '
};
typedef enum PhotoshopCCE100 PhotoshopCCE100;

enum PhotoshopCCDori {
	PhotoshopCCDoriLandscape = 'e121',
	PhotoshopCCDoriPortrait = 'e122'
};
typedef enum PhotoshopCCDori PhotoshopCCDori;

enum PhotoshopCCE130 {
	PhotoshopCCE130AbsoluteColorimetric = 'e134',
	PhotoshopCCE130Perceptual = 'e131',
	PhotoshopCCE130RelativeColorimetric = 'e133',
	PhotoshopCCE130SaturationIntent = 'e132'
};
typedef enum PhotoshopCCE130 PhotoshopCCE130;

enum PhotoshopCCE140 {
	PhotoshopCCE140Horizontal = 'e141',
	PhotoshopCCE140Vertical = 'e142'
};
typedef enum PhotoshopCCE140 PhotoshopCCE140;

enum PhotoshopCCE150 {
	PhotoshopCCE150AllCaches = 'e154',
	PhotoshopCCE150ClipboardCache = 'e153',
	PhotoshopCCE150HistoryCaches = 'e152',
	PhotoshopCCE150UndoCaches = 'e151'
};
typedef enum PhotoshopCCE150 PhotoshopCCE150;

enum PhotoshopCCE160 {
	PhotoshopCCE160BottomCenter = 'e168',
	PhotoshopCCE160BottomLeft = 'e167',
	PhotoshopCCE160BottomRight = 'e169',
	PhotoshopCCE160MiddleCenter = 'e165',
	PhotoshopCCE160MiddleLeft = 'e164',
	PhotoshopCCE160MiddleRight = 'e166',
	PhotoshopCCE160TopCenter = 'e162',
	PhotoshopCCE160TopLeft = 'e161',
	PhotoshopCCE160TopRight = 'e163'
};
typedef enum PhotoshopCCE160 PhotoshopCCE160;

enum PhotoshopCCE175 {
	PhotoshopCCE175Automatic = 'e183',
	PhotoshopCCE175Bicubic = 'e178',
	PhotoshopCCE175BicubicAutomatic = 'e182',
	PhotoshopCCE175BicubicSharper = 'e179',
	PhotoshopCCE175BicubicSmoother = 'e180',
	PhotoshopCCE175Bilinear = 'e177',
	PhotoshopCCE175ClosestNeighbor = 'e176',
	PhotoshopCCE175None = 'DNne',
	PhotoshopCCE175PreserveDetails = 'e184'
};
typedef enum PhotoshopCCE175 PhotoshopCCE175;

enum PhotoshopCCE191 {
	PhotoshopCCE191OS2 = 'e192',
	PhotoshopCCE191Windows = 'e193'
};
typedef enum PhotoshopCCE191 PhotoshopCCE191;

enum PhotoshopCCE200 {
	PhotoshopCCE200BlackAndWhite = 'e201',
	PhotoshopCCE200None = 'DNne',
	PhotoshopCCE200Primaries = 'e202',
	PhotoshopCCE200Web = 'e203'
};
typedef enum PhotoshopCCE200 PhotoshopCCE200;

enum PhotoshopCCE210 {
	PhotoshopCCE210Exact = 'e211',
	PhotoshopCCE210LocalAdaptive = 'e217',
	PhotoshopCCE210LocalPerceptual = 'e215',
	PhotoshopCCE210LocalSelective = 'e216',
	PhotoshopCCE210MacOSSystem = 'e212',
	PhotoshopCCE210MasterAdaptive = 'e220',
	PhotoshopCCE210MasterPerceptual = 'e218',
	PhotoshopCCE210MasterSelective = 'e219',
	PhotoshopCCE210Previous = 'e221',
	PhotoshopCCE210Uniform = 'e214',
	PhotoshopCCE210Web = 'e203',
	PhotoshopCCE210WindowsSystem = 'e213'
};
typedef enum PhotoshopCCE210 PhotoshopCCE210;

enum PhotoshopCCE230 {
	PhotoshopCCE230Diffusion = 'e231',
	PhotoshopCCE230Noise = 'e233',
	PhotoshopCCE230None = 'DNne',
	PhotoshopCCE230Pattern = 'e232'
};
typedef enum PhotoshopCCE230 PhotoshopCCE230;

enum PhotoshopCCE250 {
	PhotoshopCCE250EightBitMacOS = 'e254',
	PhotoshopCCE250EightBitTIFF = 'e252',
	PhotoshopCCE250JPEGMacOS = 'e255',
	PhotoshopCCE250MonochromeMacOS = 'e253',
	PhotoshopCCE250MonochromeTIFF = 'e251',
	PhotoshopCCE250None = 'DNne'
};
typedef enum PhotoshopCCE250 PhotoshopCCE250;

enum PhotoshopCCE260 {
	PhotoshopCCE260ASCII = 'e073',
	PhotoshopCCE260Binary = 'e071',
	PhotoshopCCE260HighQualityJPEG = 'e263',
	PhotoshopCCE260LowQualityJPEG = 'e261',
	PhotoshopCCE260MaximumQualityJPEG = 'e264',
	PhotoshopCCE260MediumQualityJPEG = 'e262'
};
typedef enum PhotoshopCCE260 PhotoshopCCE260;

enum PhotoshopCCE270 {
	PhotoshopCCE270Optimized = 'e272',
	PhotoshopCCE270Progressive = 'e273',
	PhotoshopCCE270Standard = 'Stdr'
};
typedef enum PhotoshopCCE270 PhotoshopCCE270;

enum PhotoshopCCE280 {
	PhotoshopCCE280JPEG = 'e006',
	PhotoshopCCE280JPEG2000High = 'JPG5',
	PhotoshopCCE280JPEG2000Lossless = 'JPGA',
	PhotoshopCCE280JPEG2000Low = 'JPG9',
	PhotoshopCCE280JPEG2000Med = 'JPG7',
	PhotoshopCCE280JPEG2000MedHigh = 'JPG6',
	PhotoshopCCE280JPEG2000MedLow = 'JPG8',
	PhotoshopCCE280JPEGHigh = 'JPG0',
	PhotoshopCCE280JPEGLow = 'JPG4',
	PhotoshopCCE280JPEGMed = 'JPG2',
	PhotoshopCCE280JPEGMedHigh = 'JPG1',
	PhotoshopCCE280JPEGMedLow = 'JPG3',
	PhotoshopCCE280None = 'DNne',
	PhotoshopCCE280ZIP = 'e281',
	PhotoshopCCE280ZIP4 = 'e282'
};
typedef enum PhotoshopCCE280 PhotoshopCCE280;

enum PhotoshopCCPD01 {
	PhotoshopCCPD01None = 'DNne',
	PhotoshopCCPD01PDFX1a2001Standard = 'PD02',
	PhotoshopCCPD01PDFX1a2003Standard = 'PD03',
	PhotoshopCCPD01PDFX32002Standard = 'PD04',
	PhotoshopCCPD01PDFX32003Standard = 'PD05',
	PhotoshopCCPD01PDFX42008Standard = 'PD33'
};
typedef enum PhotoshopCCPD01 PhotoshopCCPD01;

enum PhotoshopCCPD08 {
	PhotoshopCCPD08PDF13 = 'PD09',
	PhotoshopCCPD08PDF14 = 'PD10',
	PhotoshopCCPD08PDF15 = 'PD11',
	PhotoshopCCPD08PDF16 = 'PD12',
	PhotoshopCCPD08PDF17 = 'PD32'
};
typedef enum PhotoshopCCPD08 PhotoshopCCPD08;

enum PhotoshopCCPD16 {
	PhotoshopCCPD16None = 'DNne',
	PhotoshopCCPD16PDFAverage = 'PD17',
	PhotoshopCCPD16PDFBicubic = 'PD19',
	PhotoshopCCPD16PDFSubsample = 'PD18'
};
typedef enum PhotoshopCCPD16 PhotoshopCCPD16;

enum PhotoshopCCE290 {
	PhotoshopCCE290HighQualityJPEG = 'e263',
	PhotoshopCCE290LowQualityJPEG = 'e261',
	PhotoshopCCE290MaximumQualityJPEG = 'e264',
	PhotoshopCCE290MediumQualityJPEG = 'e262',
	PhotoshopCCE290None = 'DNne'
};
typedef enum PhotoshopCCE290 PhotoshopCCE290;

enum PhotoshopCCE300 {
	PhotoshopCCE300LowercaseExtension = 'e301',
	PhotoshopCCE300NoExtension = 'e303',
	PhotoshopCCE300UppercaseExtension = 'e302'
};
typedef enum PhotoshopCCE300 PhotoshopCCE300;

enum PhotoshopCCE320 {
	PhotoshopCCE320JPEG = 'e006',
	PhotoshopCCE320LZW = 'e321',
	PhotoshopCCE320None = 'DNne',
	PhotoshopCCE320ZIP = 'e281'
};
typedef enum PhotoshopCCE320 PhotoshopCCE320;

enum PhotoshopCCE325 {
	PhotoshopCCE325RLE = 'e326',
	PhotoshopCCE325ZIP = 'e281'
};
typedef enum PhotoshopCCE325 PhotoshopCCE325;

enum PhotoshopCCE330 {
	PhotoshopCCE330IBMPC = 'e331',
	PhotoshopCCE330MacOS = 'e332'
};
typedef enum PhotoshopCCE330 PhotoshopCCE330;

enum PhotoshopCCE340 {
	PhotoshopCCE340ColorComposite = 'e343',
	PhotoshopCCE340GrayscaleComposite = 'e342',
	PhotoshopCCE340NoCompositePostScript = 'e341'
};
typedef enum PhotoshopCCE340 PhotoshopCCE340;

enum PhotoshopCCE350 {
	PhotoshopCCE350BottomRightPixel = 'e353',
	PhotoshopCCE350TopLeftPixel = 'e352',
	PhotoshopCCE350TransparentPixels = 'e351'
};
typedef enum PhotoshopCCE350 PhotoshopCCE350;

enum PhotoshopCCE360 {
	PhotoshopCCE360AdobeColorPicker = 'e361',
	PhotoshopCCE360AppleColorPicker = 'e362',
	PhotoshopCCE360PlugInColorPicker = 'e364',
	PhotoshopCCE360WindowsColorPicker = 'e363'
};
typedef enum PhotoshopCCE360 PhotoshopCCE360;

enum PhotoshopCCE390 {
	PhotoshopCCE390AllTools = 'e392',
	PhotoshopCCE390AllWarnings = 'e391',
	PhotoshopCCE390Everything = 'e393'
};
typedef enum PhotoshopCCE390 PhotoshopCCE390;

enum PhotoshopCCE400 {
	PhotoshopCCE400Ask = 'ask ',
	PhotoshopCCE400No = 'no  ',
	PhotoshopCCE400Yes = 'yes '
};
typedef enum PhotoshopCCE400 PhotoshopCCE400;

enum PhotoshopCCE410 {
	PhotoshopCCE410BrushSize = 'e413',
	PhotoshopCCE410Precise = 'e412',
	PhotoshopCCE410Standard = 'Stdr'
};
typedef enum PhotoshopCCE410 PhotoshopCCE410;

enum PhotoshopCCE415 {
	PhotoshopCCE415Precise = 'e412',
	PhotoshopCCE415Standard = 'Stdr'
};
typedef enum PhotoshopCCE415 PhotoshopCCE415;

enum PhotoshopCCE420 {
	PhotoshopCCE420Large = 'Lrge',
	PhotoshopCCE420Medium = 'Mdum',
	PhotoshopCCE420None = 'DNne',
	PhotoshopCCE420Small = 'Smll'
};
typedef enum PhotoshopCCE420 PhotoshopCCE420;

enum PhotoshopCCE440 {
	PhotoshopCCE440CmUnits = 'Cntm',
	PhotoshopCCE440InchUnits = 'Inhs',
	PhotoshopCCE440MmUnits = 'MlMt',
	PhotoshopCCE440PercentUnits = 'Pcnt',
	PhotoshopCCE440PicaUnits = 'Pcas',
	PhotoshopCCE440PixelUnits = 'Pxls',
	PhotoshopCCE440PointUnits = 'Pnts'
};
typedef enum PhotoshopCCE440 PhotoshopCCE440;

enum PhotoshopCCE445 {
	PhotoshopCCE445MmUnits = 'MlMt',
	PhotoshopCCE445PixelUnits = 'Pxls',
	PhotoshopCCE445PointUnits = 'Pnts'
};
typedef enum PhotoshopCCE445 PhotoshopCCE445;

enum PhotoshopCCE450 {
	PhotoshopCCE450PostscriptSize = 'e451',
	PhotoshopCCE450TraditionalSize = 'e452'
};
typedef enum PhotoshopCCE450 PhotoshopCCE450;

enum PhotoshopCCE460 {
	PhotoshopCCE460DashedLine = 'e462',
	PhotoshopCCE460DottedLine = 'e463',
	PhotoshopCCE460SolidLine = 'e461'
};
typedef enum PhotoshopCCE460 PhotoshopCCE460;

enum PhotoshopCCE464 {
	PhotoshopCCE464DashedLine = 'e462',
	PhotoshopCCE464SolidLine = 'e461'
};
typedef enum PhotoshopCCE464 PhotoshopCCE464;

enum PhotoshopCCE470 {
	PhotoshopCCE470ColorBlend = 'e488',
	PhotoshopCCE470ColorBurn = 'e481',
	PhotoshopCCE470ColorDodge = 'e480',
	PhotoshopCCE470Darken = 'e482',
	PhotoshopCCE470DarkerColor = 'e497',
	PhotoshopCCE470Difference = 'e484',
	PhotoshopCCE470Dissolve = 'e490',
	PhotoshopCCE470Divide = 'e499',
	PhotoshopCCE470Exclusion = 'e485',
	PhotoshopCCE470HardLight = 'e478',
	PhotoshopCCE470HardMix = 'e495',
	PhotoshopCCE470HueBlend = 'e486',
	PhotoshopCCE470Lighten = 'e483',
	PhotoshopCCE470LighterColor = 'e496',
	PhotoshopCCE470LinearBurn = 'e491',
	PhotoshopCCE470LinearDodge = 'e492',
	PhotoshopCCE470LinearLight = 'e479',
	PhotoshopCCE470Luminosity = 'e489',
	PhotoshopCCE470Multiply = 'e472',
	PhotoshopCCE470Normal = 'Nrml',
	PhotoshopCCE470Overlay = 'e476',
	PhotoshopCCE470PassThrough = 'e471',
	PhotoshopCCE470PinLight = 'e494',
	PhotoshopCCE470SaturationBlend = 'e487',
	PhotoshopCCE470Screen = 'e474',
	PhotoshopCCE470SoftLight = 'e477',
	PhotoshopCCE470Subtract = 'e498',
	PhotoshopCCE470VividLight = 'e493'
};
typedef enum PhotoshopCCE470 PhotoshopCCE470;

enum PhotoshopCCE925 {
	PhotoshopCCE925BehindMode = 'e926',
	PhotoshopCCE925ClearMode = 'e927',
	PhotoshopCCE925ColorBlend = 'e488',
	PhotoshopCCE925ColorBurn = 'e481',
	PhotoshopCCE925ColorDodge = 'e480',
	PhotoshopCCE925Darken = 'e482',
	PhotoshopCCE925DarkerColor = 'e497',
	PhotoshopCCE925Difference = 'e484',
	PhotoshopCCE925Dissolve = 'e490',
	PhotoshopCCE925Divide = 'e499',
	PhotoshopCCE925Exclusion = 'e485',
	PhotoshopCCE925HardLight = 'e478',
	PhotoshopCCE925HardMix = 'e495',
	PhotoshopCCE925HueBlend = 'e486',
	PhotoshopCCE925Lighten = 'e483',
	PhotoshopCCE925LighterColor = 'e496',
	PhotoshopCCE925LinearBurn = 'e491',
	PhotoshopCCE925LinearDodge = 'e492',
	PhotoshopCCE925LinearLight = 'e479',
	PhotoshopCCE925Luminosity = 'e489',
	PhotoshopCCE925Multiply = 'e472',
	PhotoshopCCE925Normal = 'Nrml',
	PhotoshopCCE925Overlay = 'e476',
	PhotoshopCCE925PinLight = 'e494',
	PhotoshopCCE925SaturationBlend = 'e487',
	PhotoshopCCE925Screen = 'e474',
	PhotoshopCCE925SoftLight = 'e477',
	PhotoshopCCE925Subtract = 'e498',
	PhotoshopCCE925VividLight = 'e493'
};
typedef enum PhotoshopCCE925 PhotoshopCCE925;

enum PhotoshopCCE510 {
	PhotoshopCCE510AllLinkedLayers = 'e516',
	PhotoshopCCE510EntireLayer = 'e515',
	PhotoshopCCE510FillContent = 'e513',
	PhotoshopCCE510LayerClippingPath = 'e514',
	PhotoshopCCE510Shape = 'e512',
	PhotoshopCCE510TextContents = 'e511'
};
typedef enum PhotoshopCCE510 PhotoshopCCE510;

enum PhotoshopCCE520 {
	PhotoshopCCE520Center = 'cent',
	PhotoshopCCE520CenterJustified = 'JCtr',
	PhotoshopCCE520FullyJustified = 'JFll',
	PhotoshopCCE520Left = 'ALft',
	PhotoshopCCE520LeftJustified = 'JLft',
	PhotoshopCCE520Right = 'ARgt',
	PhotoshopCCE520RightJustified = 'JRgt'
};
typedef enum PhotoshopCCE520 PhotoshopCCE520;

enum PhotoshopCCE530 {
	PhotoshopCCE530Crisp = 'e531',
	PhotoshopCCE530None = 'DNne',
	PhotoshopCCE530Sharp = 'e534',
	PhotoshopCCE530Smoothing = 'e533',
	PhotoshopCCE530Strong = 'e532'
};
typedef enum PhotoshopCCE530 PhotoshopCCE530;

enum PhotoshopCCE540 {
	PhotoshopCCE540AllCaps = 'e541',
	PhotoshopCCE540Normal = 'Nrml',
	PhotoshopCCE540SmallCaps = 'e542'
};
typedef enum PhotoshopCCE540 PhotoshopCCE540;

enum PhotoshopCCE560 {
	PhotoshopCCE560BrazilianPortuguese = 'e563',
	PhotoshopCCE560CanadianFrench = 'e564',
	PhotoshopCCE560Danish = 'e578',
	PhotoshopCCE560Dutch = 'e577',
	PhotoshopCCE560EnglishUK = 'e576',
	PhotoshopCCE560EnglishUSA = 'e561',
	PhotoshopCCE560Finnish = 'e565',
	PhotoshopCCE560French = 'e570',
	PhotoshopCCE560German = 'e571',
	PhotoshopCCE560Italian = 'e566',
	PhotoshopCCE560Norwegian = 'e562',
	PhotoshopCCE560NynorskNorwegian = 'e567',
	PhotoshopCCE560OldGerman = 'e568',
	PhotoshopCCE560Portuguese = 'e572',
	PhotoshopCCE560Spanish = 'e569',
	PhotoshopCCE560Swedish = 'e573',
	PhotoshopCCE560SwissGerman = 'e574'
};
typedef enum PhotoshopCCE560 PhotoshopCCE560;

enum PhotoshopCCE580 {
	PhotoshopCCE580ParagraphText = 'e582',
	PhotoshopCCE580PointText = 'e581'
};
typedef enum PhotoshopCCE580 PhotoshopCCE580;

enum PhotoshopCCE600 {
	PhotoshopCCE600Arc = 'e601',
	PhotoshopCCE600ArcLower = 'e602',
	PhotoshopCCE600ArcUpper = 'e603',
	PhotoshopCCE600Arch = 'e604',
	PhotoshopCCE600Bulge = 'e605',
	PhotoshopCCE600Fish = 'e610',
	PhotoshopCCE600FishEye = 'e613',
	PhotoshopCCE600Flag = 'e608',
	PhotoshopCCE600Inflate = 'e614',
	PhotoshopCCE600None = 'DNne',
	PhotoshopCCE600Rise = 'e612',
	PhotoshopCCE600ShellLower = 'e606',
	PhotoshopCCE600ShellUpper = 'e607',
	PhotoshopCCE600Squeeze = 'e615',
	PhotoshopCCE600Twist = 'e616',
	PhotoshopCCE600Wave = 'e609'
};
typedef enum PhotoshopCCE600 PhotoshopCCE600;

enum PhotoshopCCE590 {
	PhotoshopCCE590AdobeEveryLine = 'e592',
	PhotoshopCCE590AdobeSingleLine = 'e591'
};
typedef enum PhotoshopCCE590 PhotoshopCCE590;

enum PhotoshopCCE980 {
	PhotoshopCCE980Manual = 'e981',
	PhotoshopCCE980Metrics = 'e982',
	PhotoshopCCE980Optical = 'e983'
};
typedef enum PhotoshopCCE980 PhotoshopCCE980;

enum PhotoshopCCE990 {
	PhotoshopCCE990Off = 'e991',
	PhotoshopCCE990StrikeBox = 'e993',
	PhotoshopCCE990StrikeHeight = 'e992'
};
typedef enum PhotoshopCCE990 PhotoshopCCE990;

enum PhotoshopCCEA00 {
	PhotoshopCCEA00Left = 'ALft',
	PhotoshopCCEA00Off = 'e991',
	PhotoshopCCEA00Right = 'ARgt'
};
typedef enum PhotoshopCCEA00 PhotoshopCCEA00;

enum PhotoshopCCE630 {
	PhotoshopCCE630Diminished = 'e633',
	PhotoshopCCE630Extended = 'e632',
	PhotoshopCCE630Intersected = 'e634',
	PhotoshopCCE630Replaced = 'e631'
};
typedef enum PhotoshopCCE630 PhotoshopCCE630;

enum PhotoshopCCE640 {
	PhotoshopCCE640IllustratorPaths = 'e641',
	PhotoshopCCE640SaveForWeb = 'e643'
};
typedef enum PhotoshopCCE640 PhotoshopCCE640;

enum PhotoshopCCE650 {
	PhotoshopCCE650AllPaths = 'e652',
	PhotoshopCCE650DocumentBounds = 'e651',
	PhotoshopCCE650NamedPath = 'e653'
};
typedef enum PhotoshopCCE650 PhotoshopCCE650;

enum PhotoshopCCE660 {
	PhotoshopCCE660ComponentChannel = 'e661',
	PhotoshopCCE660MaskedAreaChannel = 'e662',
	PhotoshopCCE660SelectedAreaChannel = 'e663',
	PhotoshopCCE660SpotColorChannel = 'e664'
};
typedef enum PhotoshopCCE660 PhotoshopCCE660;

enum PhotoshopCCE850 {
	PhotoshopCCE850CopyrightedWork = 'e851',
	PhotoshopCCE850PublicDomain = 'e852',
	PhotoshopCCE850Unmarked = 'e853'
};
typedef enum PhotoshopCCE850 PhotoshopCCE850;

enum PhotoshopCCE860 {
	PhotoshopCCE860CustomPattern = 'e865',
	PhotoshopCCE860DiffusionDither = 'e863',
	PhotoshopCCE860HalftoneScreenConversion = 'e864',
	PhotoshopCCE860MiddleThreshold = 'e861',
	PhotoshopCCE860PatternDither = 'e862'
};
typedef enum PhotoshopCCE860 PhotoshopCCE860;

enum PhotoshopCCE870 {
	PhotoshopCCE870HalftoneCross = 'e875',
	PhotoshopCCE870HalftoneDiamond = 'e872',
	PhotoshopCCE870HalftoneEllipse = 'e873',
	PhotoshopCCE870HalftoneLine = 'e876',
	PhotoshopCCE870HalftoneRound = 'e871',
	PhotoshopCCE870HalftoneSquare = 'e874'
};
typedef enum PhotoshopCCE870 PhotoshopCCE870;

enum PhotoshopCCE880 {
	PhotoshopCCE880BackgroundColorMatte = 'e882',
	PhotoshopCCE880BlackMatte = 'e884',
	PhotoshopCCE880ForegroundColorMatte = 'e881',
	PhotoshopCCE880NetscapeGray = 'e886',
	PhotoshopCCE880None = 'DNne',
	PhotoshopCCE880SemiGray = 'e885',
	PhotoshopCCE880WhiteMatte = 'e883'
};
typedef enum PhotoshopCCE880 PhotoshopCCE880;

enum PhotoshopCCE890 {
	PhotoshopCCE890Absolute = 'Ablt',
	PhotoshopCCE890Relative = 'RlTv'
};
typedef enum PhotoshopCCE890 PhotoshopCCE890;

enum PhotoshopCCE900 {
	PhotoshopCCE900CMYK = 'e083',
	PhotoshopCCE900Grayscale = 'e081',
	PhotoshopCCE900Lab = 'e084',
	PhotoshopCCE900RGB = 'e082'
};
typedef enum PhotoshopCCE900 PhotoshopCCE900;

enum PhotoshopCCE905 {
	PhotoshopCCE905Bitmap = 'e085',
	PhotoshopCCE905CMYK = 'e083',
	PhotoshopCCE905Grayscale = 'e081',
	PhotoshopCCE905Lab = 'e084',
	PhotoshopCCE905RGB = 'e082'
};
typedef enum PhotoshopCCE905 PhotoshopCCE905;

enum PhotoshopCCE910 {
	PhotoshopCCE910Lab16 = 'e914',
	PhotoshopCCE910Lab8 = 'e913',
	PhotoshopCCE910RGB16 = 'e912',
	PhotoshopCCE910RGB8 = 'e911'
};
typedef enum PhotoshopCCE910 PhotoshopCCE910;

enum PhotoshopCCE920 {
	PhotoshopCCE920Center = 'cent',
	PhotoshopCCE920Inside = 'e921',
	PhotoshopCCE920Outside = 'e922'
};
typedef enum PhotoshopCCE920 PhotoshopCCE920;

enum PhotoshopCCE930 {
	PhotoshopCCE930CMYK = 'e083',
	PhotoshopCCE930Grayscale = 'e081',
	PhotoshopCCE930HSB = 'e932',
	PhotoshopCCE930Lab = 'e084',
	PhotoshopCCE930RGB = 'e082',
	PhotoshopCCE930RGBHex = 'e934'
};
typedef enum PhotoshopCCE930 PhotoshopCCE930;

enum PhotoshopCCE940 {
	PhotoshopCCE940BeforeRunning = 'a942',
	PhotoshopCCE940Never = 'Nevr',
	PhotoshopCCE940OnRuntimeError = 'e941'
};
typedef enum PhotoshopCCE940 PhotoshopCCE940;

enum PhotoshopCCE945 {
	PhotoshopCCE945DocumentSpace = 'e946',
	PhotoshopCCE945ProofSpace = 'a947'
};
typedef enum PhotoshopCCE945 PhotoshopCCE945;

enum PhotoshopCCE950 {
	PhotoshopCCE950BlackAndWhiteLayer = 'e972',
	PhotoshopCCE950BrightnessContrastLayer = 'e957',
	PhotoshopCCE950ChannelMixerLayer = 'e960',
	PhotoshopCCE950ColorBalanceLayer = 'e965',
	PhotoshopCCE950ColorLookup = 'e974',
	PhotoshopCCE950CurvesLayer = 'e956',
	PhotoshopCCE950ExposureLayer = 'e969',
	PhotoshopCCE950GradientFillLayer = 'e953',
	PhotoshopCCE950GradientMapLayer = 'e961',
	PhotoshopCCE950HueSaturationLayer = 'e958',
	PhotoshopCCE950InversionLayer = 'e962',
	PhotoshopCCE950LevelsLayer = 'e955',
	PhotoshopCCE950Normal = 'Nrml',
	PhotoshopCCE950PatternFillLayer = 'e954',
	PhotoshopCCE950PhotoFilterLayer = 'e968',
	PhotoshopCCE950PosterizeLayer = 'e964',
	PhotoshopCCE950SelectiveColorLayer = 'e959',
	PhotoshopCCE950SmartObjectLayer = 'e967',
	PhotoshopCCE950SolidFillLayer = 'e952',
	PhotoshopCCE950TextLayer = 'e966',
	PhotoshopCCE950ThreeDLayer = 'e970',
	PhotoshopCCE950ThresholdLayer = 'e963',
	PhotoshopCCE950VibranceLayer = 'e973',
	PhotoshopCCE950VideoLayer = 'e971'
};
typedef enum PhotoshopCCE950 PhotoshopCCE950;

enum PhotoshopCCPDFb {
	PhotoshopCCPDFbBlindsHorizontal = 'PDFc',
	PhotoshopCCPDFbBlindsVertical = 'PDFd',
	PhotoshopCCPDFbBoxIn = 'PDFe',
	PhotoshopCCPDFbBoxOut = 'PDFf',
	PhotoshopCCPDFbDissolve = 'e490',
	PhotoshopCCPDFbGlitterDown = 'PDFg',
	PhotoshopCCPDFbGlitterRight = 'PDFh',
	PhotoshopCCPDFbGlitterRightDown = 'PDFi',
	PhotoshopCCPDFbNone = 'DNne',
	PhotoshopCCPDFbRandom = 'PDFj',
	PhotoshopCCPDFbSplitHorizontalIn = 'PDFk',
	PhotoshopCCPDFbSplitHorizontalOut = 'PDFl',
	PhotoshopCCPDFbSplitVerticalIn = 'PDFm',
	PhotoshopCCPDFbSplitVerticalOut = 'PDFn',
	PhotoshopCCPDFbWipeDown = 'PDFo',
	PhotoshopCCPDFbWipeLeft = 'PDFp',
	PhotoshopCCPDFbWipeRight = 'PDFq',
	PhotoshopCCPDFbWipeUp = 'PDFr'
};
typedef enum PhotoshopCCPDFb PhotoshopCCPDFb;

enum PhotoshopCCPGa2 {
	PhotoshopCCPGa2Arial = 'PG03',
	PhotoshopCCPGa2CourierNew = 'PG04',
	PhotoshopCCPGa2Helvetica = 'PG05',
	PhotoshopCCPGa2TimesNewRoman = 'PG07'
};
typedef enum PhotoshopCCPGa2 PhotoshopCCPGa2;

enum PhotoshopCCPGa3 {
	PhotoshopCCPGa3ConstrainBoth = 'PG10',
	PhotoshopCCPGa3ConstrainHeight = 'PG09',
	PhotoshopCCPGa3ConstrainWidth = 'PG08'
};
typedef enum PhotoshopCCPGa3 PhotoshopCCPGa3;

enum PhotoshopCCPGa4 {
	PhotoshopCCPGa4GalleryCustom = 'PG14',
	PhotoshopCCPGa4GalleryLarge = 'PG13',
	PhotoshopCCPGa4GalleryMedium = 'PG12',
	PhotoshopCCPGa4GallerySmall = 'PG11'
};
typedef enum PhotoshopCCPGa4 PhotoshopCCPGa4;

enum PhotoshopCCPGa5 {
	PhotoshopCCPGa5GalleryCaption = 'PG19',
	PhotoshopCCPGa5GalleryCopyright = 'PG18',
	PhotoshopCCPGa5GalleryCredit = 'PG20',
	PhotoshopCCPGa5GalleryCustomText = 'PG16',
	PhotoshopCCPGa5GalleryFilename = 'PG17',
	PhotoshopCCPGa5GalleryNone = 'PG15',
	PhotoshopCCPGa5GalleryTitle = 'PG21'
};
typedef enum PhotoshopCCPGa5 PhotoshopCCPGa5;

enum PhotoshopCCPP09 {
	PhotoshopCCPP09CaptionText = 'PP05',
	PhotoshopCCPP09CopyrightText = 'PP04',
	PhotoshopCCPP09CreditText = 'PP06',
	PhotoshopCCPP09FilenameText = 'PP03',
	PhotoshopCCPP09NoText = 'PP02',
	PhotoshopCCPP09OriginText = 'PP07',
	PhotoshopCCPP09UserText = 'PP08'
};
typedef enum PhotoshopCCPP09 PhotoshopCCPP09;

enum PhotoshopCCPGa6 {
	PhotoshopCCPGa6GallerySecurityBlack = 'PG22',
	PhotoshopCCPGa6GallerySecurityCustom = 'PG24',
	PhotoshopCCPGa6GallerySecurityWhite = 'PG23'
};
typedef enum PhotoshopCCPGa6 PhotoshopCCPGa6;

enum PhotoshopCCPGa7 {
	PhotoshopCCPGa7GalleryCentered = 'PG25',
	PhotoshopCCPGa7GalleryLowerLeft = 'PG27',
	PhotoshopCCPGa7GalleryLowerRight = 'PG29',
	PhotoshopCCPGa7GalleryUpperLeft = 'PG26',
	PhotoshopCCPGa7GalleryUpperRight = 'PG28'
};
typedef enum PhotoshopCCPGa7 PhotoshopCCPGa7;

enum PhotoshopCCPGa8 {
	PhotoshopCCPGa8ClockWise45 = 'PG31',
	PhotoshopCCPGa8ClockWise90 = 'PG32',
	PhotoshopCCPGa8CounterClockWise45 = 'PG33',
	PhotoshopCCPGa8CounterClockWise90 = 'PG34',
	PhotoshopCCPGa8Zero = 'PG30'
};
typedef enum PhotoshopCCPGa8 PhotoshopCCPGa8;

enum PhotoshopCCMX00 {
	PhotoshopCCMX00Always = 'e051',
	PhotoshopCCMX00Ask = 'ask ',
	PhotoshopCCMX00Never = 'Nevr'
};
typedef enum PhotoshopCCMX00 PhotoshopCCMX00;

enum PhotoshopCCPr49 {
	PhotoshopCCPr49Both = 'Pr52',
	PhotoshopCCPr49LogFile = 'Pr51',
	PhotoshopCCPr49Metadata = 'Pr50'
};
typedef enum PhotoshopCCPr49 PhotoshopCCPr49;

enum PhotoshopCCPr53 {
	PhotoshopCCPr53Concise = 'Pr55',
	PhotoshopCCPr53Detailed = 'Pr56',
	PhotoshopCCPr53Sessiononly = 'Pr54'
};
typedef enum PhotoshopCCPr53 PhotoshopCCPr53;

enum PhotoshopCCBT14 {
	PhotoshopCCBT14Folder = 'BT16',
	PhotoshopCCBT14None = 'DNne',
	PhotoshopCCBT14SaveAndClose = 'BT15'
};
typedef enum PhotoshopCCBT14 PhotoshopCCBT14;

enum PhotoshopCCBT17 {
	PhotoshopCCBT17Ddmm = 'BT33',
	PhotoshopCCBT17Ddmmyy = 'BT32',
	PhotoshopCCBT17DocumentName3 = 'BT20',
	PhotoshopCCBT17DocumentNameLower = 'BT19',
	PhotoshopCCBT17DocumentNameMixed = 'BT18',
	PhotoshopCCBT17ExtensionLower = 'BT34',
	PhotoshopCCBT17ExtensionUpper = 'BT35',
	PhotoshopCCBT17Mmdd = 'BT28',
	PhotoshopCCBT17Mmddyy = 'BT27',
	PhotoshopCCBT17SerialLetterLower = 'BT25',
	PhotoshopCCBT17SerialLetterUpper = 'BT26',
	PhotoshopCCBT17SerialNumberFour = 'BT24',
	PhotoshopCCBT17SerialNumberOne = 'BT21',
	PhotoshopCCBT17SerialNumberThree = 'BT23',
	PhotoshopCCBT17SerialNumberTwo = 'BT22',
	PhotoshopCCBT17Yyddmm = 'BT31',
	PhotoshopCCBT17Yymmdd = 'BT30',
	PhotoshopCCBT17Yyyymmdd = 'BT29'
};
typedef enum PhotoshopCCBT17 PhotoshopCCBT17;

enum PhotoshopCCLB00 {
	PhotoshopCCLB00ImageHighlight = 'LB02',
	PhotoshopCCLB00LayerMask = 'LB01',
	PhotoshopCCLB00None = 'DNne',
	PhotoshopCCLB00TransparencyChannel = 'LB17'
};
typedef enum PhotoshopCCLB00 PhotoshopCCLB00;

enum PhotoshopCCLB03 {
	PhotoshopCCLB03Heptagon = 'LB08',
	PhotoshopCCLB03Hexagon = 'LB07',
	PhotoshopCCLB03Octagon = 'LB09',
	PhotoshopCCLB03Pentagon = 'LB06',
	PhotoshopCCLB03Square = 'e733',
	PhotoshopCCLB03Triangle = 'LB04'
};
typedef enum PhotoshopCCLB03 PhotoshopCCLB03;

enum PhotoshopCCCR38 {
	PhotoshopCCCR38Adaptive = 'CR41',
	PhotoshopCCCR38BlackWhite = 'CR44',
	PhotoshopCCCR38CustomReduction = 'CR35',
	PhotoshopCCCR38Grayscale = 'e081',
	PhotoshopCCCR38MacintoshColors = 'CR45',
	PhotoshopCCCR38PerceptualReduction = 'CR39',
	PhotoshopCCCR38Restrictive = 'CR42',
	PhotoshopCCCR38Selective = 'CR40',
	PhotoshopCCCR38WindowsColors = 'CR37'
};
typedef enum PhotoshopCCCR38 PhotoshopCCCR38;

enum PhotoshopCCCR02 {
	PhotoshopCCCR02CameraDefault = 'CR03',
	PhotoshopCCCR02CustomSettings = 'CR36',
	PhotoshopCCCR02SelectedImage = 'CR04'
};
typedef enum PhotoshopCCCR02 PhotoshopCCCR02;

enum PhotoshopCCCR05 {
	PhotoshopCCCR05AsShot = 'CR06',
	PhotoshopCCCR05Auto = 'CR07',
	PhotoshopCCCR05Cloudy = 'CR09',
	PhotoshopCCCR05CustomCameraSettings = 'CR18',
	PhotoshopCCCR05Daylight = 'CR08',
	PhotoshopCCCR05Flash = 'CR13',
	PhotoshopCCCR05Fluorescent = 'CR12',
	PhotoshopCCCR05Shade = 'CR10',
	PhotoshopCCCR05Tungsten = 'CR11'
};
typedef enum PhotoshopCCCR05 PhotoshopCCCR05;

enum PhotoshopCCCR46 {
	PhotoshopCCCR46AdobeRGB = 'CR47',
	PhotoshopCCCR46ColorMatchRGB = 'CR48',
	PhotoshopCCCR46ProPhotoRGB = 'CR49',
	PhotoshopCCCR46SRGB = 'CR50'
};
typedef enum PhotoshopCCCR46 PhotoshopCCCR46;

enum PhotoshopCCCR34 {
	PhotoshopCCCR34ExtraLarge = 'e811',
	PhotoshopCCCR34Large = 'Lrge',
	PhotoshopCCCR34Maximum = 'Maxi',
	PhotoshopCCCR34Medium = 'Mdum',
	PhotoshopCCCR34Minimum = 'Mini',
	PhotoshopCCCR34Small = 'Smll'
};
typedef enum PhotoshopCCCR34 PhotoshopCCCR34;

enum PhotoshopCCPDFx {
	PhotoshopCCPDFxActualSize = 'PDFy',
	PhotoshopCCPDFxFitPage = 'PDFz'
};
typedef enum PhotoshopCCPDFx PhotoshopCCPDFx;

enum PhotoshopCCCrtO {
	PhotoshopCCCrtOArtBox = 'crt6',
	PhotoshopCCCrtOBleedBox = 'crt4',
	PhotoshopCCCrtOBoundingBox = 'crt1',
	PhotoshopCCCrtOCropBox = 'crt3',
	PhotoshopCCCrtOMediaBox = 'crt2',
	PhotoshopCCCrtOTrimBox = 'crt5'
};
typedef enum PhotoshopCCCrtO PhotoshopCCCrtO;

enum PhotoshopCCFP00 {
	PhotoshopCCFP00ExtraLarge = 'e811',
	PhotoshopCCFP00None = 'DNne',
	PhotoshopCCFP00PreviewHuge = 'FP05',
	PhotoshopCCFP00PreviewLarge = 'FP03',
	PhotoshopCCFP00PreviewMedium = 'FP02',
	PhotoshopCCFP00PreviewSmall = 'FP01'
};
typedef enum PhotoshopCCFP00 PhotoshopCCFP00;

enum PhotoshopCCME00 {
	PhotoshopCCME00MeasureCountTool = 'ME02',
	PhotoshopCCME00MeasureRulerTool = 'ME03',
	PhotoshopCCME00MeasureSelection = 'ME01'
};
typedef enum PhotoshopCCME00 PhotoshopCCME00;

enum PhotoshopCCE810 {
	PhotoshopCCE810ExtraLarge = 'e811',
	PhotoshopCCE810Large = 'Lrge',
	PhotoshopCCE810Maximum = 'Maxi',
	PhotoshopCCE810Medium = 'Mdum',
	PhotoshopCCE810Minimum = 'Mini',
	PhotoshopCCE810Small = 'Smll'
};
typedef enum PhotoshopCCE810 PhotoshopCCE810;

enum PhotoshopCCE840 {
	PhotoshopCCE840Eight = 'Eigt',
	PhotoshopCCE840Four = 'Four',
	PhotoshopCCE840Sixteen = 'STen',
	PhotoshopCCE840ThirtyTwo = 'Tty2',
	PhotoshopCCE840Two = 'Two '
};
typedef enum PhotoshopCCE840 PhotoshopCCE840;

enum PhotoshopCCE845 {
	PhotoshopCCE845Sixteen = 'STen',
	PhotoshopCCE845ThirtyTwo = 'Tty2',
	PhotoshopCCE845TwentyFour = 'TyFr'
};
typedef enum PhotoshopCCE845 PhotoshopCCE845;

enum PhotoshopCCE820 {
	PhotoshopCCE820A1R5G5B5 = 'e828',
	PhotoshopCCE820A4R4G4B4 = 'e831',
	PhotoshopCCE820A8R8G8B8 = 'e834',
	PhotoshopCCE820Eight = 'Eigt',
	PhotoshopCCE820Four = 'Four',
	PhotoshopCCE820One = 'One ',
	PhotoshopCCE820R5G6B5 = 'e829',
	PhotoshopCCE820R8G8B8 = 'e832',
	PhotoshopCCE820Sixteen = 'STen',
	PhotoshopCCE820ThirtyTwo = 'Tty2',
	PhotoshopCCE820TwentyFour = 'TyFr',
	PhotoshopCCE820X1R5G5B5 = 'e827',
	PhotoshopCCE820X4R4G4B4 = 'e830',
	PhotoshopCCE820X8R8G8B8 = 'e833'
};
typedef enum PhotoshopCCE820 PhotoshopCCE820;

enum PhotoshopCCE670 {
	PhotoshopCCE670Spin = 'e671',
	PhotoshopCCE670Zoom = 'e672'
};
typedef enum PhotoshopCCE670 PhotoshopCCE670;

enum PhotoshopCCE675 {
	PhotoshopCCE675Best = 'e678',
	PhotoshopCCE675Draft = 'e676',
	PhotoshopCCE675Good = 'e677'
};
typedef enum PhotoshopCCE675 PhotoshopCCE675;

enum PhotoshopCCE680 {
	PhotoshopCCE680High = 'e107',
	PhotoshopCCE680Low = 'e101',
	PhotoshopCCE680Medium = 'Mdum'
};
typedef enum PhotoshopCCE680 PhotoshopCCE680;

enum PhotoshopCCE685 {
	PhotoshopCCE685EdgeOnly = 'e686',
	PhotoshopCCE685Normal = 'Nrml',
	PhotoshopCCE685OverlayEdge = 'e687'
};
typedef enum PhotoshopCCE685 PhotoshopCCE685;

enum PhotoshopCCE690 {
	PhotoshopCCE690Blocks = 'e691',
	PhotoshopCCE690Canvas = 'e692',
	PhotoshopCCE690Frosted = 'e693',
	PhotoshopCCE690TextureDocument = 'e695',
	PhotoshopCCE690TinyLens = 'e694'
};
typedef enum PhotoshopCCE690 PhotoshopCCE690;

enum PhotoshopCCE700 {
	PhotoshopCCE700PolarToRectangular = 'e702',
	PhotoshopCCE700RectangularToPolar = 'e701'
};
typedef enum PhotoshopCCE700 PhotoshopCCE700;

enum PhotoshopCCE710 {
	PhotoshopCCE710Large = 'Lrge',
	PhotoshopCCE710Medium = 'Mdum',
	PhotoshopCCE710Small = 'Smll'
};
typedef enum PhotoshopCCE710 PhotoshopCCE710;

enum PhotoshopCCE715 {
	PhotoshopCCE715RepeatEdgePixels = 'e717',
	PhotoshopCCE715WrapAround = 'e716'
};
typedef enum PhotoshopCCE715 PhotoshopCCE715;

enum PhotoshopCCE718 {
	PhotoshopCCE718RepeatEdgePixels = 'e717',
	PhotoshopCCE718SetToLayerFill = 'e719',
	PhotoshopCCE718WrapAround = 'e716'
};
typedef enum PhotoshopCCE718 PhotoshopCCE718;

enum PhotoshopCCE720 {
	PhotoshopCCE720Horizontal = 'e141',
	PhotoshopCCE720Normal = 'Nrml',
	PhotoshopCCE720Vertical = 'e142'
};
typedef enum PhotoshopCCE720 PhotoshopCCE720;

enum PhotoshopCCE725 {
	PhotoshopCCE725StretchToFit = 'e726',
	PhotoshopCCE725Tile = 'e727'
};
typedef enum PhotoshopCCE725 PhotoshopCCE725;

enum PhotoshopCCE730 {
	PhotoshopCCE730Sine = 'e731',
	PhotoshopCCE730Square = 'e733',
	PhotoshopCCE730Triangular = 'e732'
};
typedef enum PhotoshopCCE730 PhotoshopCCE730;

enum PhotoshopCCE740 {
	PhotoshopCCE740AroundCenter = 'e741',
	PhotoshopCCE740OutFromCenter = 'e742',
	PhotoshopCCE740PondRipples = 'e743'
};
typedef enum PhotoshopCCE740 PhotoshopCCE740;

enum PhotoshopCCE745 {
	PhotoshopCCE745Gaussian = 'e746',
	PhotoshopCCE745Uniform = 'e214'
};
typedef enum PhotoshopCCE745 PhotoshopCCE745;

enum PhotoshopCCE750 {
	PhotoshopCCE750MoviePrime = 'e753',
	PhotoshopCCE750Prime105 = 'e752',
	PhotoshopCCE750Prime35 = 'e751',
	PhotoshopCCE750Zoom = 'e672'
};
typedef enum PhotoshopCCE750 PhotoshopCCE750;

enum PhotoshopCCE755 {
	PhotoshopCCE755EvenFields = 'e757',
	PhotoshopCCE755OddFields = 'e756'
};
typedef enum PhotoshopCCE755 PhotoshopCCE755;

enum PhotoshopCCE760 {
	PhotoshopCCE760Duplication = 'e761',
	PhotoshopCCE760Interpolation = 'e762'
};
typedef enum PhotoshopCCE760 PhotoshopCCE760;

enum PhotoshopCCPT21 {
	PhotoshopCCPT21Clipping = 'PT05',
	PhotoshopCCPT21Normal = 'Nrml',
	PhotoshopCCPT21TextMask = 'PT58',
	PhotoshopCCPT21VectorMask = 'PT57',
	PhotoshopCCPT21Work = 'PT06'
};
typedef enum PhotoshopCCPT21 PhotoshopCCPT21;

enum PhotoshopCCPT45 {
	PhotoshopCCPT45ShapeAdd = 'PT46',
	PhotoshopCCPT45ShapeIntersect = 'PT48',
	PhotoshopCCPT45ShapeSubtract = 'PT49',
	PhotoshopCCPT45ShapeXor = 'PT47'
};
typedef enum PhotoshopCCPT45 PhotoshopCCPT45;

enum PhotoshopCCPT22 {
	PhotoshopCCPT22CornerPoint = 'PT24',
	PhotoshopCCPT22SmoothPoint = 'PT25'
};
typedef enum PhotoshopCCPT22 PhotoshopCCPT22;

enum PhotoshopCCPT23 {
	PhotoshopCCPT23ArtHistoryBrushTool = 'PT34',
	PhotoshopCCPT23BackgroundEraserTool = 'PT29',
	PhotoshopCCPT23BlurTool = 'PT36',
	PhotoshopCCPT23BrushTool = 'PT27',
	PhotoshopCCPT23BurnTool = 'PT39',
	PhotoshopCCPT23CloneStampTool = 'PT30',
	PhotoshopCCPT23ColorReplacementTool = 'PT41',
	PhotoshopCCPT23DodgeTool = 'PT38',
	PhotoshopCCPT23EraserTool = 'PT28',
	PhotoshopCCPT23HealingBrushTool = 'PT32',
	PhotoshopCCPT23HistoryBrushTool = 'PT33',
	PhotoshopCCPT23PatternStampTool = 'PT31',
	PhotoshopCCPT23PencilTool = 'PT26',
	PhotoshopCCPT23SharpenTool = 'PT37',
	PhotoshopCCPT23SmudgeTool = 'PT35',
	PhotoshopCCPT23SpongeTool = 'PT40'
};
typedef enum PhotoshopCCPT23 PhotoshopCCPT23;



/*
 * Core Suite
 */

// The Adobe Photoshop application
@interface PhotoshopCCApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) fonts;
- (SBElementArray *) notifiers;

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy) PhotoshopCCColorValue *backgroundColor;
@property (copy, readonly) NSString *build;  // the build number of Adobe Photoshop application
@property (copy) id colorSettings;  // name of selected color settings' set
@property (copy) PhotoshopCCDocument *currentDocument;  // the frontmost document
@property (copy) NSString *currentTool;  // name of the current tool
@property PhotoshopCCE050 displayDialogs;  // controls whether or not Photoshop displays dialogs
@property (copy) PhotoshopCCColorValue *foregroundColor;
@property (readonly) double freeMemory;  // the amount of unused memory available to Adobe Photoshop
@property (readonly) BOOL frontmost;  // is Photoshop the frontmost application?
@property (copy, readonly) NSString *locale;  // language locale of application
@property (copy, readonly) NSArray *macintoshFileTypes;  // list of file image types Photoshop can open
@property (copy, readonly) NSString *name;  // the application's name
@property BOOL notifiersEnabled;  // enable or disable all notifiers
@property (copy, readonly) id preferencesFolder;  // full path to the preferences folder
@property (copy, readonly) NSArray *recentFiles;  // files in the recent file list
@property (copy, readonly) NSString *scriptingBuildDate;  // the build date of the scripting interface
@property (copy, readonly) NSString *scriptingVersion;  // the version of the Scripting interface
@property (copy, readonly) PhotoshopCCSettingsObject *settings;  // preference settings
@property (copy, readonly) NSString *systemInformation;  // system information of the host application and machine
@property (copy, readonly) NSString *version;  // the version of Adobe Photoshop application
@property (copy, readonly) NSArray *windowsFileTypes;  // list of file image extensions Photoshop can open

- (void) AETEScriptsScriptsJavaScriptNameName:(NSString *)JavaScriptNameName JavaScriptFileFile:(NSString *)JavaScriptFileFile JavaScriptTextText:(NSString *)JavaScriptTextText JavaScriptDebuggingDebugging:(BOOL)JavaScriptDebuggingDebugging JavaScriptMessageMessage:(NSString *)JavaScriptMessageMessage;  // Photoshop scripting support plug-in
- (void) open:(id)x as:(PhotoshopCCOpAs)as withOptions:(PhotoshopCCOpenOptions *)withOptions showingDialogs:(PhotoshopCCE050)showingDialogs smartObject:(BOOL)smartObject;  // open the specified document file(s)
- (void) print:(id)x sourceSpace:(PhotoshopCCE945)sourceSpace printSpace:(NSString *)printSpace intent:(PhotoshopCCE130)intent blackpointCompensation:(BOOL)blackpointCompensation;  // print the specified object(s)
- (void) quit;  // quit the application
- (NSArray *) PhotoshopOpenDialog;  // use the Photoshop open dialog to select files
- (NSString *) batch:(NSString *)x fromFiles:(NSArray *)fromFiles from:(NSString *)from withOptions:(PhotoshopCCBatchOptions *)withOptions;  // run the batch automation routine
- (NSString *) createPDFPresentationFromFiles:(NSArray *)fromFiles toFile:(id)toFile withOptions:(PhotoshopCCPresentationOptions *)withOptions;  // create a PDF presentation file
- (NSString *) createContactSheetFromFiles:(NSArray *)fromFiles withOptions:(PhotoshopCCContactSheetOptions *)withOptions;  // create a contact sheet from multiple files
- (NSString *) createPhotoGalleryFromFolder:(id)fromFolder toFolder:(id)toFolder withOptions:(PhotoshopCCGalleryOptions *)withOptions;  // Creates a web photo gallery
- (NSString *) createPhotoMergeFromFiles:(NSArray *)fromFiles;  // DEPRECATED. Merges multiple files into one, user interaction required.
- (NSString *) createPicturePackageFromFiles:(NSArray *)fromFiles withOptions:(PhotoshopCCPicturePackageOptions *)withOptions;  // create a picture package from multiple files
- (BOOL) featureEnabledName:(NSString *)name;  // is the feature with the given name enabled?
- (void) purge:(PhotoshopCCE150)x;  // purges one or more caches
- (void) refresh;  // pause the script until the application refreshes
- (PhotoshopCCRGBColor *) webSafeColorFor:(PhotoshopCCColorValue *)for_;  // find the closest web safe color for a color
- (void) clear;  // clear current selection
- (void) copy;  // copy current selection to the clipboard
- (void) copyMerged;  // copy current selection to the clipboard. Include data in all visible layers.
- (void) cut;  // cut current selection to the clipboard
- (void) doAction:(NSString *)x from:(NSString *)from;  // play an action from the Actions Palette
- (NSString *) doJavascript:(id)x withArguments:(NSArray *)withArguments showDebugger:(PhotoshopCCE940)showDebugger;  // execute a JavaScript
- (void) pasteClippingToSelection:(BOOL)clippingToSelection;  // paste clipboard into the current document

@end

// A document
@interface PhotoshopCCDocument : SBObject

- (SBElementArray *) artLayers;
- (SBElementArray *) channels;
- (SBElementArray *) colorSamplers;
- (SBElementArray *) countItems;
- (SBElementArray *) historyStates;
- (SBElementArray *) layerComps;
- (SBElementArray *) layers;
- (SBElementArray *) layerSets;
- (SBElementArray *) pathItems;

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) PhotoshopCCArtLayer *backgroundLayer;  // The background layer for the document. Only valid for documents that have a background layer
@property PhotoshopCCE815 bitsPerChannel;  // number of bits per channel
@property PhotoshopCCE090 colorProfileKind;  // Type of color profile management for document.  Note: If you want to set a custom color profile, do not set a value for color profile kind; rather, set the appropriate color profile name.
@property (copy) NSString *colorProfileName;  // Name of color profile for document. Valid when no value is specified for color profile kind (to indicate a custom color profile).
@property (copy, readonly) NSArray *componentChannels;  // all color component channels for this document
@property (copy) NSArray *currentChannels;  // selected channels for document
@property (copy) PhotoshopCCHistoryState *currentHistoryBrushSource;  // the current history state to use with the history brush for this document
@property (copy) PhotoshopCCHistoryState *currentHistoryState;  // the current history state for this document
@property (copy) PhotoshopCCLayer *currentLayer;  // selected layer for document
@property (copy, readonly) id filePath;  // full path name of document
@property (readonly) double height;  // height of document (unit value)
@property (copy, readonly) NSArray *histogram;  // a histogram of values for the composite document (only for RGB, CMYK and 'Indexed colors' documents)
- (NSInteger) id;  // the unique ID of this document
@property (copy, readonly) PhotoshopCCInfoObject *info;  // document information
@property (readonly) PhotoshopCCE110 initialFill;  // initial fill of the document. Only valid when used as an option with the 'make new document' command
@property (readonly) BOOL managed;  // is the document a workgroup document?
@property (copy, readonly) PhotoshopCCMeasurementScale *measurementScale;  // The measurement scale of the document
@property (readonly) PhotoshopCCE080 mode;  // document mode
@property (readonly) BOOL modified;  // has the document been modified since last save?
@property (copy, readonly) NSString *name;  // the document's name
@property double pixelAspectRatio;  // the pixel aspect ration of the document
@property BOOL quickMaskMode;  // is the document in the quick mask mode?
@property (readonly) double resolution;  // the resolution of the document (in pixels per inch)
@property (copy, readonly) PhotoshopCCSelectionObject *selection;  // the document's selection
@property (readonly) double width;  // width of document (unit value)
@property (copy, readonly) PhotoshopCCXMPMetadata *XMPMetadata;  // XMP metadata associated with the document

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (void) closeSaving:(PhotoshopCCSavo)saving;  // close the document
- (PhotoshopCCDocument *) duplicate;  // duplicate this document without parameters
- (PhotoshopCCDocument *) saveIn:(id)in_ as:(PhotoshopCCSvFm)as copying:(BOOL)copying appending:(PhotoshopCCE300)appending withOptions:(PhotoshopCCSaveOptions *)withOptions;  // save the specified document
- (void) autoCountFrom:(PhotoshopCCChannel *)from threshold:(NSInteger)threshold;  // automatically counts the objects in an image
- (void) changeModeTo:(PhotoshopCCE089)to withOptions:(PhotoshopCCChangeModeOptions *)withOptions;  // change the mode of the document
- (void) convertToProfile:(NSString *)toProfile intent:(PhotoshopCCE130)intent blackpointCompensation:(BOOL)blackpointCompensation dithering:(BOOL)dithering;  // convert the document from using one color profile to using an other
- (void) cropBounds:(NSArray *)bounds angle:(double)angle width:(double)width height:(double)height;  // crop the document
- (void) deselect;
- (PhotoshopCCDocument *) docDuplicateName:(NSString *)name mergeLayersOnly:(BOOL)mergeLayersOnly;  // duplicate this document with parameters
- (void) exportIn:(id)in_ as:(PhotoshopCCE640)as withOptions:(PhotoshopCCExportOptions *)withOptions;
- (void) flatten;  // Flattens all visible layers in the document.
- (void) flipCanvasDirection:(PhotoshopCCE140)direction;  // flip the canvas horizontally or vertically
- (void) importAnnotationsFrom:(id)from;  // import annotations into the document
- (void) mergeVisibleLayers;  // flatten all visible layers in the document
- (void) recordMeasurementsSource:(PhotoshopCCME00)source dataPoints:(NSArray *)dataPoints;  // record measurements of document
- (void) resizeCanvasWidth:(double)width height:(double)height anchorPosition:(PhotoshopCCE160)anchorPosition;  // change the size of the canvas
- (void) resizeImageWidth:(double)width height:(double)height resolution:(double)resolution resampleMethod:(PhotoshopCCE175)resampleMethod amount:(NSInteger)amount;  // change the size of the image
- (void) revealAll;  // expand document to show clipped sections
- (void) rotateCanvasAngle:(double)angle;  // rotate canvas of document
- (void) selectRegion:(NSArray *)region combinationType:(PhotoshopCCE630)combinationType featherAmount:(double)featherAmount antialiasing:(BOOL)antialiasing;  // change the selection
- (void) selectAll;  // select the entire image
- (NSArray *) splitChannels;  // split channels of the document
- (void) trapWidth:(NSInteger)width;  // apply trap to a CMYK document
- (void) trimBasingTrimOn:(PhotoshopCCE350)basingTrimOn topTrim:(BOOL)topTrim leftTrim:(BOOL)leftTrim bottomTrim:(BOOL)bottomTrim rightTrim:(BOOL)rightTrim;

@end



/*
 * Photoshop Suite
 */

// options for the Batch command
@interface PhotoshopCCBatchOptions : SBObject

@property PhotoshopCCBT14 destination;  // final destination of processed files ( default: none )
@property (copy) id destinationFolder;  // folder location when using destination to a folder
@property (copy) id errorFile;  // file to log errors encountered, leave this blank to stop for errors
@property (copy) NSArray *fileNaming;  // list of file naming options 6 max.
@property BOOL macintoshCompatible;  // make final file name Macintosh compatible ( default: true )
@property BOOL overrideOpen;  // override action open commands ( default: false )
@property BOOL overrideSave;  // override save as action steps with destination specified here ( default: false )
@property NSInteger startingserial;  // starting serial number to use ( default: 1 )
@property BOOL suppressOpen;  // suppress file open options dialogs ( default: false )
@property BOOL suppressprofile;  // suppress color profile warnings ( default: false )
@property BOOL unixCompatible;  // make final file name Unix compatible ( default: true )
@property BOOL windowsCompatible;  // make final file name Windows compatible ( default: true )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// used with options on the 'change mode' command
@interface PhotoshopCCChangeModeOptions : SBObject

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Settings related to changing the document mode to Bitmap
@interface PhotoshopCCBitmapModeOptions : PhotoshopCCChangeModeOptions

@property double angle;  // only valid for 'halftone screen' conversions
@property PhotoshopCCE860 conversionMethod;  // ( default: diffusion dither )
@property double frequency;  // only valid for 'halftone screen' conversions
@property (copy) NSString *patternName;  // only valid for 'custom pattern' conversions
@property double resolution;  // output resolution (in pixels per inch) ( default: 72.0 )
@property PhotoshopCCE870 screenShape;  // only valid for 'halftone screen' conversions


@end

// A channel in a document. Can be either a component channel representing a color of the document color model or an alpha channel
@interface PhotoshopCCChannel : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy) PhotoshopCCColorValue *channelColor;  // color of the channel (not valid for component channels)
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy, readonly) NSArray *histogram;  // a histogram of values for the channel
@property PhotoshopCCE660 kind;  // type of the channel
@property (copy) NSString *name;  // the channel's name
@property double opacity;  // opacity of alpha channels (called solidity for spot channels)
@property BOOL visible;

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (void) merge;  // Merges an art layer or layer set into the layer below, or merges a spot channel into the component channels. Merging a layer or layer set returns a reference to the resulting layer. Merging a channel does not return any value.

@end

// A color sampler in a document. See the color sampler tool.
@interface PhotoshopCCColorSampler : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) PhotoshopCCColorValue *colorSamplerColor;  // color of the color sampler
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy, readonly) NSArray *position;  // position of the color sampler (unit value)

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Options for the Contact Sheet command
@interface PhotoshopCCContactSheetOptions : SBObject

@property BOOL acrossFirst;  // place the images horizontally first ( default: true )
@property BOOL autoSpacing;  // auto space the images in the contact sheet ( default: true )
@property BOOL bestFit;  // rotate images for best fit ( default: false )
@property BOOL caption;  // use the filename as a caption for the image ( default: true )
@property NSInteger columnCount;  // contact sheet columns ( default: 5 )
@property BOOL flattenFinal;  // flatten all layers in the final document ( default: true )
@property PhotoshopCCPGa2 font;  // font used for the caption ( default: Arial )
@property NSInteger fontSize;  // font size used for the caption ( default: 12 )
@property NSInteger height;  // height of the resulting document in pixels ( default: 720 )
@property NSInteger horizontalOffset;  // horizontal spacing between images in pixels ( default: 1 )
@property PhotoshopCCE905 mode;  // document mode (Grayscale, RGB, CMYK or Lab) ( default: RGB )
@property double resolution;  // the resolution of the document (in pixels per inch) ( default: 72.0 )
@property NSInteger rowCount;  // contact sheet rows ( default: 6 )
@property NSInteger verticalOffset;  // vertical spacing between images in pixels ( default: 1 )
@property NSInteger width;  // width of the resulting document in pixels ( default: 576 )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// A counted item in a document. See the counting tool.
@interface PhotoshopCCCountItem : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy, readonly) NSArray *position;  // position of count item (unit value)

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// An installed font
@interface PhotoshopCCFont : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) NSString *family;  // the font's family
@property (copy, readonly) NSString *name;  // The font's text face name
@property (copy, readonly) NSString *PostScriptName;  // the font's PostScript name
@property (copy, readonly) NSString *style;  // the font's style name

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Options for the web photo gallery banner options
@interface PhotoshopCCGalleryBannerOptions : SBObject

@property (copy) NSString *contactInfo;  // web photo gallery contact info ( default:  )
@property (copy) NSString *date;  // web photo gallery date ( default:  )
@property PhotoshopCCPGa2 font;  // the font setting for the banner text ( default: Arial )
@property NSInteger fontSize;  // the size of the font for the banner text ( 1 - 7; default: 3 )
@property (copy) NSString *photographer;  // web photo gallery photographer ( default:  )
@property (copy) NSString *siteName;  // web photo gallery site name ( default: Adobe Web Photo Gallery )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Options for the web photo gallery colors
@interface PhotoshopCCGalleryColorOptions : SBObject

@property (copy) PhotoshopCCRGBColor *activeLinkColor;  // active link color
@property (copy) PhotoshopCCRGBColor *backgroundColor;  // background color
@property (copy) PhotoshopCCRGBColor *bannerColor;  // banner color
@property (copy) PhotoshopCCRGBColor *linkColor;  // link color
@property (copy) PhotoshopCCRGBColor *textColor;  // text color
@property (copy) PhotoshopCCRGBColor *visitedLinkColor;  // visited link color

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Options for the web photo gallery images
@interface PhotoshopCCGalleryImagesOptions : SBObject

@property NSInteger border;  // the amount of border pixels you want between your images ( 0 - 99; default: 0 )
@property BOOL caption;  // generate a caption for the images ( default: false )
@property NSInteger dimension;  // resized image dimensions in pixels ( default: 350 )
@property PhotoshopCCPGa2 font;  // font for the gallery images text ( default: Arial )
@property NSInteger fontSize;  // font size for the gallery images text ( 1 - 7; default: 3 )
@property NSInteger imageQuality;  // the quality setting for the JPEG image ( 0 - 12; default: 5 )
@property BOOL includeCopyright;  // include the copyright in the text for the gallery images ( default: false )
@property BOOL includeCredits;  // include the credits in the text for the gallery images ( default: false )
@property BOOL includeFileName;  // include the file name in the text for the gallery images ( default: true )
@property BOOL includeTitle;  // include the title in the text for the gallery images ( default: false )
@property BOOL numericLinks;  // add numeric links ( default: true )
@property PhotoshopCCPGa3 resizeConstraint;  // how should the image be constrained ( default: constrain both )
@property BOOL resizeImages;  // resize images data ( default: true )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Options for the web photo gallery command
@interface PhotoshopCCGalleryOptions : SBObject

@property (copy) PhotoshopCCGalleryBannerOptions *bannerOptions;  // options related to banner settings
@property (copy) PhotoshopCCGalleryColorOptions *customColorOptions;  // options related to custom color settings
@property (copy) NSString *emailAddress;  // the email address to show on the web page ( default:  )
@property (copy) PhotoshopCCGalleryImagesOptions *imagesOptions;  // options related to images settings
@property (copy) NSString *layoutStyle;  // the style to use for laying out the web page ( default: Centered Frame 1 - Basic )
@property BOOL preserveAllMetadata;  // save all of the metadata in the JPEG files ( default: false )
@property (copy) PhotoshopCCGallerySecurityOptions *securityOptions;  // options related to security settings
@property BOOL shortExtension;  // short web page extension .htm or long web page extension .html ( default: true )
@property BOOL sizeAttributes;  // add width and height attributes for images ( default: true )
@property BOOL subFolders;  // include all files found in sub folders of the input folder ( default: true )
@property (copy) PhotoshopCCGalleryThumbnailOptions *thumbnailOptions;  // options related to thumbnail settings
@property BOOL UTF8Encoding;  // web page should use UTF-8 encoding ( default: false )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Options for the web photo gallery security
@interface PhotoshopCCGallerySecurityOptions : SBObject

@property PhotoshopCCPGa5 content;  // web photo gallery security content ( default: gallery none )
@property (copy) NSString *customText;  // web photo gallery security custom text ( default:  )
@property PhotoshopCCPGa2 font;  // web photo gallery security font ( default: Arial )
@property NSInteger fontSize;  // web photo gallery security font size ( minimum 1; default: 36 )
@property NSInteger opacity;  // web page security opacity as a percent ( default: 100 )
@property (copy) PhotoshopCCRGBColor *textColor;  // web page security text color
@property PhotoshopCCPGa7 textPosition;  // web photo gallery security text position ( default: gallery centered )
@property PhotoshopCCPGa8 textRotate;  // web photo gallery security text rotate ( default: zero )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Options for the web photo gallery thumbnail creation
@interface PhotoshopCCGalleryThumbnailOptions : SBObject

@property NSInteger border;  // the amount of border pixels you want around your thumbnail images ( 0 - 99; default: 0 )
@property BOOL caption;  // with caption ( default: false )
@property NSInteger columnCount;  // web photo gallery thumbnail columns ( default: 5 )
@property NSInteger dimension;  // web photo gallery thumbnail dimension in pixels ( default: 75 )
@property PhotoshopCCPGa2 font;  // web photo gallery font ( default: Arial )
@property NSInteger fontSize;  // the size of the font for the thumbnail images text ( 1 - 7; default: 3 )
@property BOOL includeCopyright;  // include copyright for thumbnail ( default: false )
@property BOOL includeCredits;  // include credits for thumbnail ( default: false )
@property BOOL includeFileName;  // include file name for thumbnail ( default: false )
@property BOOL includeTitle;  // include title for thumbnail ( default: false )
@property NSInteger rowCount;  // web photo gallery thumbnail rows ( default: 3 )
@property PhotoshopCCPGa4 size;  // the size of the thumbnail images ( default: gallery medium )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// A history state for the document
@interface PhotoshopCCHistoryState : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy, readonly) NSString *name;  // the history state's name
@property (readonly) BOOL snapshot;  // is the history state a snapshot?

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Settings related to changing the document mode to Indexed
@interface PhotoshopCCIndexedModeOptions : PhotoshopCCChangeModeOptions

@property NSInteger colorsInPalette;  // number of colors in palette (only settable for some palette types)
@property PhotoshopCCE230 dither;  // type of dither
@property NSInteger ditherAmount;  // amount of dither. Only valid for diffusion ( 1 - 100 )
@property PhotoshopCCE200 forcedColors;
@property PhotoshopCCE880 matte;
@property PhotoshopCCE210 palette;  // Type of palette ( default: exact )
@property BOOL preserveExactColors;
@property BOOL transparency;


@end

// Document information
@interface PhotoshopCCInfoObject : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy) NSString *author;
@property (copy) NSString *authorPosition;
@property (copy) NSString *caption;
@property (copy) NSString *captionWriter;
@property (copy) NSString *category;
@property (copy) NSString *city;
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy) NSString *copyrightNotice;
@property PhotoshopCCE850 copyrighted;
@property (copy) NSString *country;
@property (copy) NSString *creationDate;
@property (copy) NSString *credit;
@property (copy, readonly) NSArray *EXIF;
@property (copy) NSString *headline;
@property (copy) NSString *instructions;
@property (copy) NSString *jobName;
@property (copy) NSArray *keywords;  // list of keywords
@property (copy) NSString *ownerUrl;
@property (copy) NSString *provinceOrState;
@property (copy) NSString *source;
@property (copy) NSArray *supplementalCategories;
@property (copy) NSString *title;
@property (copy) NSString *transmissionReference;
@property PhotoshopCCE100 urgency;

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// A layer object
@interface PhotoshopCCLayer : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property BOOL allLocked;
@property PhotoshopCCE470 blendMode;
@property (copy, readonly) NSArray *bounds;  // Bounding rectangle of the Layer
@property (copy, readonly) SBObject *container;  // the object's container
- (NSInteger) id;  // the unique ID of this layer
@property (readonly) NSInteger itemindex;  // the layer index sans layer groups, how Photoshop would index them
@property (copy, readonly) NSArray *linkedLayers;
@property (copy) NSString *name;  // the name of the layer
@property double opacity;  // master opacity of layer ( 0.0 - 100.0 )
@property BOOL visible;

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (void) linkWith:(PhotoshopCCLayer *)with;  // link the layer with another layer
- (void) rotateAngle:(double)angle anchorPosition:(PhotoshopCCE160)anchorPosition;
- (void) scaleHorizontalScale:(double)horizontalScale verticalScale:(double)verticalScale anchorPosition:(PhotoshopCCE160)anchorPosition;
- (void) translateDeltaX:(double)deltaX deltaY:(double)deltaY;  // moves the position relative to its current position
- (void) unlink;  // unlink the layer

@end

// any layer that can contain data
@interface PhotoshopCCArtLayer : PhotoshopCCLayer

@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property BOOL backgroundLayer;  // is the layer a background layer?
@property double fillOpacity;  // the interior opacity of the layer (between 0.0 and 100.0)
@property BOOL grouped;  // is the layer grouped with the layer below?. Photoshop CS changed the menu name to Create/Release Clipping Mask
@property PhotoshopCCE950 kind;  // to create a text layer set this property to 'text layer' on an empty art layer of type 'normal'
@property BOOL pixelsLocked;
@property BOOL positionLocked;
@property (copy, readonly) PhotoshopCCTextObject *textObject;  // the text that is associated with the art layer. Only valid for art layers whose 'kind' is a text layer
@property BOOL transparentPixelsLocked;

- (void) applyLayerStyleUsing:(NSString *)using_;
- (void) rasterizeAffecting:(PhotoshopCCE510)affecting;
- (void) filterUsing:(id)using_ withOptions:(PhotoshopCCFilterOptions *)withOptions;  // apply a filter to one or more art layers
- (void) adjustUsing:(id)using_ withOptions:(PhotoshopCCAdjustmentOptions *)withOptions;  // apply an adjustment to one or more art layers

@end

// A layer composition in a document
@interface PhotoshopCCLayerComp : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property BOOL appearance;  // use layer appearance
@property (copy) id comment;  // the description of the layer comp
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy) NSString *name;  // the name of the layer comp
@property BOOL position;  // use layer position
@property (readonly) BOOL selected;  // the layer comp is currently selected
@property BOOL visibility;  // use layer visibility

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (void) apply;  // apply the layer comp to the document
- (void) recapture;  // recapture the current layer state(s) for this layer comp
- (void) resetFromComp;  // reset the layer comp state to the document state

@end

// Layer set
@interface PhotoshopCCLayerSet : PhotoshopCCLayer

- (SBElementArray *) artLayers;
- (SBElementArray *) layers;
- (SBElementArray *) layerSets;

@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy) NSArray *enabledChannels;  // channels that are enabled for the layer set. Must be a list of component channels


@end

// Document Measurement Scale
@interface PhotoshopCCMeasurementScale : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) SBObject *container;  // the object's container
@property double logicalLength;  // the logical length this scale equates to
@property (copy) NSString *logicalUnits;  // the logical units for this scale
@property (copy) NSString *name;  // the name of this scale
@property NSInteger pixelLength;  // the length in pixels this scale equates to

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// options for the Picture Package command
@interface PhotoshopCCPicturePackageOptions : SBObject

@property PhotoshopCCPP09 content;  // content information ( default: no text )
@property (copy) NSString *customText;  // picture package custom text ( default:  )
@property BOOL flattenFinal;  // flatten all layers in the final document ( default: true )
@property PhotoshopCCPGa2 font;  // font used for the text ( default: Arial )
@property NSInteger fontSize;  // font size used for the caption ( default: 12 )
@property (copy) NSString *layout;  // layout to use to generate the picture package ( default: (2)5x7 )
@property PhotoshopCCE905 mode;  // document mode (Grayscale, RGB, CMYK or Lab) ( default: RGB )
@property NSInteger opacity;  // web page security opacity as a percent ( default: 100 )
@property double resolution;  // the resolution of the document (in pixels per inch) ( default: 72.0 )
@property (copy) PhotoshopCCRGBColor *textColor;  // text color
@property PhotoshopCCPGa7 textPosition;  // text position ( default: gallery centered )
@property PhotoshopCCPGa8 textRotate;  // text rotate ( default: zero )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// options for the PDF presentation command
@interface PhotoshopCCPresentationOptions : SBObject

@property BOOL autoAdvance;  // auto advance when viewing ( default: true )
@property BOOL includeFileName;  // include file name for image ( default: false )
@property NSInteger interval;  // time in seconds before auto advancing the view ( default: 5 )
@property BOOL loop;  // loop after last page ( default: false )
@property PhotoshopCCPDFx magnification;  // magnification type when viewing the image ( default: actual size )
@property (copy) PhotoshopCCPDFSaveOptions *PDFOptions;  // Options used when creating the PDF file
@property BOOL presentation;  // true if the file type is presentation false for Multi-Page document ( default: false )
@property PhotoshopCCPDFb transition;  // transition type when switching to the next document ( default: none )

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// The selection of the document
@interface PhotoshopCCSelectionObject : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) NSArray *bounds;  // bounding rectangle of the entire selection
@property (copy, readonly) SBObject *container;  // the object's container
@property (readonly) BOOL solid;  // is the bounding rectangle a solid rectangle

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (void) contractBy:(double)by;  // contracts the selection
- (void) expandBy:(double)by;  // expand selection
- (void) featherBy:(double)by;  // feather edges of selection
- (void) fillWithContents:(id)withContents blendMode:(PhotoshopCCE925)blendMode opacity:(NSInteger)opacity preservingTransparency:(BOOL)preservingTransparency;  // fills the selection
- (void) growTolerance:(NSInteger)tolerance antialiasing:(BOOL)antialiasing;  // grow selection to include all adjacent pixels falling within the specified tolerance range
- (void) invert;  // invert the selection
- (void) loadFrom:(PhotoshopCCChannel *)from combinationType:(PhotoshopCCE630)combinationType inverting:(BOOL)inverting;  // load the selection from a channel
- (void) makeWorkPathTolerance:(double)tolerance;  // make this selection item the work path for this document
- (void) rotateBoundaryAngle:(double)angle anchorPosition:(PhotoshopCCE160)anchorPosition;  // rotates the boundary of selection
- (void) scaleBoundaryHorizontalScale:(double)horizontalScale verticalScale:(double)verticalScale anchorPosition:(PhotoshopCCE160)anchorPosition;  // scale the boundary of selection
- (void) selectBorderWidth:(double)width;  // select the border of the selection
- (void) similarTolerance:(NSInteger)tolerance antialiasing:(BOOL)antialiasing;  // grow selection to include pixels throughout the image falling within the tolerance range
- (void) smoothRadius:(NSInteger)radius;
- (void) storeInto:(PhotoshopCCChannel *)into combinationType:(PhotoshopCCE630)combinationType;  // save the selection as a channel
- (void) strokeUsingColor:(id)usingColor width:(NSInteger)width location:(PhotoshopCCE920)location blendMode:(PhotoshopCCE925)blendMode opacity:(NSInteger)opacity preservingTransparency:(BOOL)preservingTransparency;  // strokes the selection
- (void) translateBoundaryDeltaX:(double)deltaX deltaY:(double)deltaY;  // moves the boundary of selection relative to its current position

@end

// Preferences for Photoshop
@interface PhotoshopCCSettingsObject : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy) id additionalPluginFolder;
@property PhotoshopCCE400 appendExtension;
@property BOOL askBeforeSavingLayeredTIFF;
@property BOOL autoUpdateOpenDocuments;
@property BOOL beepWhenDone;
@property NSInteger cacheLevels;
@property PhotoshopCCE360 colorPicker;
@property double columnGutter;  // gutter of columns (in points)
@property double columnWidth;  // width of columns (in points)
@property BOOL createFirstSnapshot;  // automatically make first snapshot when a new document is created?
@property BOOL displayColorChannelsInColor;
@property BOOL dynamicColorSliders;
@property PhotoshopCCPr53 editLogItems;  // options for edit log items
@property BOOL exportClipboard;
@property PhotoshopCCFP00 fontPreviewSize;  // show font previews in the type tool font menus
@property BOOL fullSizePreview;
@property double gamutWarningOpacity;
@property PhotoshopCCE420 gridSize;
@property PhotoshopCCE460 gridStyle;
@property NSInteger gridSubdivisions;
@property PhotoshopCCE464 guideStyle;
@property BOOL iconPreview;
@property PhotoshopCCE400 imagePreviews;
@property PhotoshopCCE175 interpolationMethod;
@property BOOL keyboardZoomResizesWindows;
@property BOOL MacOSThumbnail;
@property PhotoshopCCMX00 maximizeCompatibility;  // maximize compatibility for Photoshop (PSD) files
@property NSInteger maximumRAMUse;  // Maximum percentage of available RAM used by Photoshop ( 5 - 100 )
@property BOOL nonlinearHistory;  // allow non-linear history?
@property NSInteger numberOfHistoryStates;  // number of history states to remember (between 1 and 100)
@property PhotoshopCCE415 otherCursors;
@property PhotoshopCCE410 paintingCursors;
@property BOOL pixelDoubling;
@property PhotoshopCCE450 pointSize;  // size of point/pica
@property NSInteger recentFileListLength;  // number of items in the recent file list (between 0 and 30)
@property PhotoshopCCE440 rulerUnits;  // Note: this is the unit that the scripting system will use when receiving and returning values
@property PhotoshopCCPr49 saveLogItems;  // options for saving the history items
@property (copy) id saveLogItemsFile;  // file to save the history log
@property BOOL savePaletteLocations;
@property BOOL showAsianTextOptions;
@property BOOL showEnglishFontNames;
@property BOOL showSliceNumbers;
@property BOOL showToolTips;
@property BOOL smartQuotes;
@property PhotoshopCCE445 typeUnits;
@property BOOL useAdditionalPluginFolder;
@property BOOL useCacheForHistograms;
@property BOOL useDiffusionDither;
@property BOOL useHistoryLog;  // Turn on and off the history logging
@property BOOL useLowercaseExtension;  // should the file extension be lowercase
@property BOOL useShiftKeyForToolSwitch;
@property BOOL useVideoAlpha;  // this option requires hardware support
@property BOOL WindowsThumbnail;

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Text object contained in an art layer
@interface PhotoshopCCTextObject : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property BOOL alternateLigatures;  // use alternate ligatures?
@property PhotoshopCCE530 antialiasMethod;
@property PhotoshopCCE980 autoKerning;  // options for auto kerning
@property BOOL autoLeading;  // whether to use a font's built-in leading information
@property double autoLeadingAmount;  // percentage to use for auto leading
@property double baselineShift;  // baseline offset of text (unit value)
@property PhotoshopCCE540 capitalization;  // the case of the text
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy) NSString *contents;  // the text in the layer
@property double desiredGlyphScaling;
@property double desiredLetterScaling;
@property double desiredWordScaling;
@property BOOL fauxBold;  // use faux bold?
@property BOOL fauxItalic;  // use faux italic?
@property double firstLineIndent;  // (unit value)
@property (copy) NSString *font;  // text face of the character
@property double height;  // the height of paragraph text (unit value)
@property NSInteger horizontalScale;  // horizontal scaling of characters (in percent)
@property double horizontalWarpDistortion;  // percentage from -100 to 100
@property NSInteger hyphenLimit;  // maximum number of consecutive hyphens
@property NSInteger hyphenateAfterFirst;  // hyphenate after this many letters
@property NSInteger hyphenateBeforeLast;  // hyphenate before this many letters
@property BOOL hyphenateCapitalizedWords;  // wheter to hyphenate capitalized words
@property NSInteger hyphenateWordsLongerThan;  // hyphenate words that have more than this number of letters ( minimum 0 )
@property BOOL hyphenation;  // use hyphenation?
@property double hyphenationZone;  // the hyphenation zone (unit value)
@property PhotoshopCCE520 justification;  // paragraph justification
@property PhotoshopCCE580 kind;  // the type of the text
@property PhotoshopCCE560 language;
@property double leading;  // leading (unit value)
@property double leftIndent;  // (unit value)
@property BOOL ligatures;  // use ligatures?
@property double maximumGlyphScaling;
@property double maximumLetterScaling;
@property double maximumWordScaling;
@property double minimumGlyphScaling;
@property double minimumLetterScaling;
@property double minimumWordScaling;
@property BOOL noBreak;
@property BOOL oldStyle;  // use old style?
@property (copy) NSArray *position;  // position of origin (unit value)
@property double rightIndent;  // (unit value)
@property BOOL RomanHangingPunctuation;  // use Roman Hanging Punctuation?
@property double size;  // font size in points
@property double spaceAfter;  // (unit value)
@property double spaceBefore;  // (unit value)
@property PhotoshopCCE990 strikeThru;  // options for strik thru of the text
@property (copy) PhotoshopCCColorValue *strokeColor;  // color of text
@property PhotoshopCCE590 textComposer;  // type of text composing engine to use
@property PhotoshopCCE140 textDirection;  // text orientation
@property double tracking;  // controls uniform spacing between multiple characters
@property PhotoshopCCEA00 underline;  // options for underlining of the text
@property NSInteger verticalScale;  // vertical scaling of characters (in percent)
@property double verticalWarpDistortion;  // percentage from -100 to 100
@property double warpBend;  // percentage from -100 to 100
@property PhotoshopCCE140 warpDirection;
@property PhotoshopCCE600 warpStyle;
@property double width;  // the width of paragraph text (unit value)

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (void) convertToShape;  // converts the text object and its containing layer to a fill layer with the text changed to a clipping path
- (void) createWorkPath;  // creates a work path based on the text object

@end

@interface PhotoshopCCXMPMetadata : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy) NSString *rawData;  // raw XML form of file information

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end



/*
 * Open Formats Suite
 */

// used with options on the open command
@interface PhotoshopCCOpenOptions : SBObject

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Settings related to opening a camera RAW document
@interface PhotoshopCCCameraRAWOpenOptions : PhotoshopCCOpenOptions

@property PhotoshopCCE815 bitsPerChannel;  // number of bits per channel
@property NSInteger blueHue;  // the blue hue of the shot
@property NSInteger blueSaturation;  // the blue saturation of the shot
@property NSInteger brightness;  // the brightness of the shot
@property NSInteger chromaticAberrationBy;  // the chromatic aberration B/Y of the shot
@property NSInteger chromaticAberrationRc;  // the chromatic aberration R/C of the shot
@property NSInteger colorNoiseReduction;  // the color noise reduction of the shot
@property PhotoshopCCCR46 colorSpace;  // colorspace for image
@property NSInteger contrast;  // the constrast of the shot
@property double exposure;  // the exposure of the shot
@property NSInteger greenHue;  // the green hue of the shot
@property NSInteger greenSaturation;  // the green saturation of the shot
@property NSInteger luminanceSmoothing;  // the luminance smoothing of the shot
@property NSInteger redHue;  // the red hue of the shot
@property NSInteger redSaturation;  // the red saturation of the shot
@property double resolution;  // the resolution of the document (in pixels per inch)
@property NSInteger saturation;  // the saturation of the shot
@property PhotoshopCCCR02 settings;  // global settings for all Camera RAW options ( default: camera default )
@property NSInteger shadowTint;  // the shadow tint of the shot
@property NSInteger shadows;  // the shadows of the shot
@property NSInteger sharpness;  // the sharpness of the shot
@property PhotoshopCCCR34 size;  // size of the new document
@property NSInteger temperature;  // the temperature of the shot
@property NSInteger tint;  // the tint of the shot
@property NSInteger vignettingAmount;  // the vignetting amount of the shot
@property NSInteger vignettingMidpoint;  // the vignetting mid point of the shot
@property PhotoshopCCCR05 whiteBalance;  // white balance options for the image


@end

// Settings related to opening a DICOM document
@interface PhotoshopCCDICOMOpenOptions : PhotoshopCCOpenOptions

@property BOOL anonymize;  // Anonymize the patient information
@property NSInteger columns;  // The number of columns in n-up configuration
@property BOOL reverse;  // Reverse(Invert) the image
@property NSInteger rows;  // The number of rows in n-up configuration
@property BOOL show_overlays;  // Show Overlays (if present)
@property NSInteger windowlevel;  // Window Level
@property NSInteger windowwidth;  // Window Width


@end

// Settings related to opening a generic EPS document
@interface PhotoshopCCEPSOpenOptions : PhotoshopCCOpenOptions

@property BOOL constrainProportions;  // constrain proportions of image
@property double height;  // height of image (unit value)
@property PhotoshopCCE900 mode;  // the document mode
@property double resolution;  // the resolution of the document (in pixels per inch)
@property BOOL useAntialias;  // use antialias?
@property double width;  // width of image (unit value)


@end

// Settings related to opening a generic PDF document
@interface PhotoshopCCPDFOpenOptions : PhotoshopCCOpenOptions

@property PhotoshopCCE815 bitsPerChannel;  // number of bits per channel
@property BOOL constrainProportions;  // DEPRECATED, no longer used in CS2 ( constrain proportions of image )
@property PhotoshopCCCrtO cropPage;  // crop the page
@property double height;  // DEPRECATED, no longer used in CS2  ( height of image (unit value) )
@property PhotoshopCCE900 mode;  // the document mode
@property (copy) NSString *name;  // name of the new document
@property NSInteger object;  // number of 3d object to open
@property NSInteger page;  // number of page or image to open
@property double resolution;  // the resolution of the document (in pixels per inch)
@property BOOL suppressWarnings;  // supress any warnings that may occur during opening
@property BOOL use3dObjectNumber;  // 3d property refers to using 3d object, if false then UsePageNumber is used
@property BOOL useAntialias;  // use antialias?
@property BOOL usePageNumber;  // page property refers to page number, if false page property refers to image number
@property double width;  // DEPRECATED, no longer used in CS2  ( width of image (unit value) )


@end

// Settings related to opening a PhotoCD document
@interface PhotoshopCCPhotoCDOpenOptions : PhotoshopCCOpenOptions

@property (copy) NSString *colorProfileName;  // profile to use when reading the image
@property PhotoshopCCE910 colorSpace;  // colorspace for image
@property PhotoshopCCDori orientation;
@property PhotoshopCCE810 pixelSize;  // dimensions of image
@property double resolution;  // the resolution of the image (in pixels per inch)


@end

// Settings related to opening a raw format document
@interface PhotoshopCCRawFormatOpenOptions : PhotoshopCCOpenOptions

@property NSInteger bitsPerChannel;  // number of bits for each channel (8 or 16)
@property PhotoshopCCE330 byteOrder;  // only relevant for images with 16 bits per channel
@property NSInteger headerSize;
@property NSInteger height;  // height of image (in pixels)
@property BOOL interleaveChannels;  // are the channels in the image interleaved?
@property NSInteger numberOfChannels;  // number of channels in image
@property BOOL retainHeader;  // retain header when saving?
@property NSInteger width;  // width of image (in pixels)


@end



/*
 * Save Formats Suite
 */

// used with options on the save command
@interface PhotoshopCCSaveOptions : SBObject

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Settings related to saving a BMP document
@interface PhotoshopCCBMPSaveOptions : PhotoshopCCSaveOptions

@property PhotoshopCCE820 bitsPerSample;  // number of bits per sample ( default: twenty four )
@property BOOL flippedRowOrder;
@property BOOL RLECompression;  // should RLE compression be used?
@property BOOL saveAlphaChannels;  // save alpha channels
@property PhotoshopCCE191 targetOperatingSystem;  // target OS. Windows or OS/2 ( default: Windows )


@end

// Settings related to saving an EPS document
@interface PhotoshopCCEPSSaveOptions : PhotoshopCCSaveOptions

@property BOOL embedColorProfile;  // embed color profile in document
@property PhotoshopCCE260 encoding;  // type of encoding to use for document ( default: binary )
@property BOOL halftoneScreen;  // include halftone screen ( default: false )
@property BOOL imageInterpolation;  // use image interpolation ( default: false )
@property BOOL PostScriptColorManagement;  // use Postscript color management ( default: false )
@property PhotoshopCCE250 previewType;  // type of preview ( default: monochrome TIFF )
@property BOOL transferFunction;  // include transfer functions in document ( default: false )
@property BOOL transparentWhites;  // only valid when saving BitMap documents
@property BOOL vectorData;  // include vector data


@end

// Settings related to saving a GIF document
@interface PhotoshopCCGIFSaveOptions : PhotoshopCCSaveOptions

@property NSInteger colorsInPalette;  // number of colors in palette (only settable for some palette types)
@property PhotoshopCCE230 dither;  // type of dither
@property NSInteger ditherAmount;  // amount of dither. Only valid for diffusion ( 1 - 100; default: 75 )
@property PhotoshopCCE200 forcedColors;
@property BOOL interlaced;  // should rows be interlaced? ( default: false )
@property PhotoshopCCE880 matte;
@property PhotoshopCCE210 palette;  // ( default: local selective )
@property BOOL preserveExactColors;
@property BOOL transparency;


@end

// Settings related to saving a JPEG document
@interface PhotoshopCCJPEGSaveOptions : PhotoshopCCSaveOptions

@property BOOL embedColorProfile;  // embed color profile in document
@property PhotoshopCCE270 formatOptions;  // ( default: standard )
@property PhotoshopCCE880 matte;
@property NSInteger quality;  // quality of produced image ( 0 - 12; default: 3 )
@property NSInteger scans;  // number of scans. Only valid for progressive type JPEG files ( 3 - 5 )


@end

// Settings related to saving a pdf document
@interface PhotoshopCCPDFSaveOptions : PhotoshopCCSaveOptions

@property BOOL colorConversion;  // convert the color profile to a destination profile
@property (copy) NSString *objectDescription;  // description of the save options in use
@property (copy) NSString *destinationProfile;  // describes the final RGB or CMYK output device, such as your monitor or a certain press standard
@property PhotoshopCCPD16 downSample;  // down sample method to use
@property double downSampleLimit;  // limits downsampleing/subsampling to images that exceed this value (in pixels per inch)
@property double downSampleSize;  // down sample images to this size if they exceed limit (in pixels per inch)
@property BOOL downgradeColorProfile;  // DEPRECATED, no longer used in CS2 ( should the embedded color profile be downgraded to version 2 )
@property BOOL eightConvert;  // converts a 16-bit image to 8-bit for better compatibility with other applications
@property BOOL embedColorProfile;  // embed color profile in document
@property BOOL embedFonts;  // DEPRECATED, no longer used in CS2 ( embed fonts? Only valid if a text layer is included )
@property BOOL embedThumbnail;  // Includes a small preview image in Acrobat
@property PhotoshopCCE280 encoding;  // ZIP, JPEG and JPEG2000 encoding and compression options
@property BOOL imageInterpolation;  // DEPRECATED, no longer used in CS2 ( use image interpolation? )
@property NSInteger JPEGQuality;  // Only valid for JPEG encoding. Use encoding options instead of this property. Quality of produced image. Only valid for JPEG encoded PDF documents ( 0 - 12 )
@property (copy) NSString *outputCondition;  // an optional comment field for inserting descriptions of the output condition. The text is stored in the PDF/X file.
@property (copy) NSString *outputConditionId;  // identifier for the output condition
@property PhotoshopCCPD08 PDFCompatibility;  // PDF version to be compatible with
@property PhotoshopCCPD01 PDFStandard;  // PDF Standard to be compatible with
@property BOOL preserveEditing;  // Lets you reopen the PDF in Photoshop with native Photoshop data intact
@property (copy) NSString *presetfile;  // preset file to use for settings, may override 'save as' dialog settings
@property BOOL profileInclusionPolicy;  // shows which profiles to include
@property (copy) NSString *registryName;  // URL where the output condition is registered
@property BOOL saveAlphaChannels;  // save alpha channels
@property BOOL saveAnnotations;  // save annotations
@property BOOL saveLayers;  // save layers
@property BOOL saveSpotColors;  // save spot colors
@property NSInteger tileSize;  // compression option supported only with JPEG2000 compression
@property BOOL transparency;  // DEPRECATED, no longer used in CS2
@property BOOL useOutlinesForText;  // DEPRECATED, no longer used in CS2 ( use outlines for text? Only valid if vector data is included )
@property BOOL vectorData;  // DEPRECATED, no longer used in CS2 ( include vector data )
@property BOOL view;  // Opens the saved PDF in Acrobat
@property BOOL webOptimize;  // Improves performance of PDFs on Web servers


@end

// Settings related to saving a Photoshop DCS 1.0 document
@interface PhotoshopCCPhotoshopDCS10SaveOptions : PhotoshopCCSaveOptions

@property PhotoshopCCE340 DCS;  // ( default: color composite )
@property BOOL embedColorProfile;  // embed color profile in document
@property PhotoshopCCE260 encoding;  // type of encoding to use for document ( default: binary )
@property BOOL halftoneScreen;  // include halftone screen ( default: false )
@property BOOL imageInterpolation;  // use image interpolation ( default: false )
@property PhotoshopCCE250 previewType;  // type of preview ( default: eight bit Mac OS )
@property BOOL transferFunction;  // include transfer functions in document ( default: false )
@property BOOL vectorData;  // include vector data


@end

// Settings related to saving a Photoshop DCS 2.0 document
@interface PhotoshopCCPhotoshopDCS20SaveOptions : PhotoshopCCSaveOptions

@property PhotoshopCCE340 DCS;  // ( default: no composite PostScript )
@property BOOL embedColorProfile;  // embed color profile in document
@property PhotoshopCCE260 encoding;  // type of encoding to use for document ( default: binary )
@property BOOL halftoneScreen;  // include halftone screen ( default: false )
@property BOOL imageInterpolation;  // use image interpolation ( default: false )
@property BOOL multifileDCS;  // ( default: false )
@property PhotoshopCCE250 previewType;  // type of preview ( default: eight bit Mac OS )
@property BOOL saveSpotColors;  // save spot colors
@property BOOL transferFunction;  // include transfer functions in document ( default: false )
@property BOOL vectorData;  // include vector data


@end

// Settings related to saving a Photoshop document
@interface PhotoshopCCPhotoshopSaveOptions : PhotoshopCCSaveOptions

@property BOOL embedColorProfile;  // embed color profile in document
@property BOOL saveAlphaChannels;  // save alpha channels
@property BOOL saveAnnotations;  // save annotations
@property BOOL saveLayers;  // save layers
@property BOOL saveSpotColors;  // save spot colors


@end

// Settings related to saving a PICT document
@interface PhotoshopCCPICTFileSaveOptions : PhotoshopCCSaveOptions

@property PhotoshopCCE290 compression;  // ( default: none )
@property BOOL embedColorProfile;  // embed color profile in document
@property PhotoshopCCE840 resolution;  // number of bits per pixel
@property BOOL saveAlphaChannels;  // save alpha channels


@end

// Settings related to saving a PICT resource file
@interface PhotoshopCCPICTResourceSaveOptions : PhotoshopCCSaveOptions

@property PhotoshopCCE290 compression;  // ( default: none )
@property BOOL embedColorProfile;  // embed color profile in document
@property (copy) NSString *name;  // name of PICT resource ( default: "" )
@property PhotoshopCCE840 resolution;  // number of bits per pixel
@property NSInteger resourceId;  // ID of PICT resource ( default: 128 )
@property BOOL saveAlphaChannels;  // save alpha channels


@end

// Settings related to saving a Pixar document
@interface PhotoshopCCPixarSaveOptions : PhotoshopCCSaveOptions

@property BOOL saveAlphaChannels;  // save alpha channels


@end

// Settings related to saving a PNG document
@interface PhotoshopCCPNGSaveOptions : PhotoshopCCSaveOptions

@property NSInteger compression;  // compression used on the image. ( 0 - 9; default: 0 )
@property BOOL interlaced;  // should rows be interlaced? ( default: false )


@end

// Settings related to saving a document in raw format
@interface PhotoshopCCRawSaveOptions : PhotoshopCCSaveOptions

@property BOOL saveAlphaChannels;  // save alpha channels
@property BOOL saveSpotColors;  // save spot colors


@end

// Settings related to saving a document in the SGI RGB format
@interface PhotoshopCCSGIRGBSaveOptions : PhotoshopCCSaveOptions

@property BOOL saveAlphaChannels;  // save alpha channels
@property BOOL saveSpotColors;  // save spot colors


@end

// Settings related to saving a Target document
@interface PhotoshopCCTargaSaveOptions : PhotoshopCCSaveOptions

@property PhotoshopCCE845 resolution;  // number of bits per pixel ( default: twenty four )
@property BOOL RLECompression;  // should RLE compression be used? ( default: true )
@property BOOL saveAlphaChannels;  // save alpha channels


@end

// Settings related to saving a TIFF document
@interface PhotoshopCCTIFFSaveOptions : PhotoshopCCSaveOptions

@property PhotoshopCCE330 byteOrder;  // Default value is 'Mac OS' when running on MacOS, and 'IBM PC' when running on a PC
@property BOOL embedColorProfile;  // embed color profile in document
@property PhotoshopCCE320 imageCompression;  // compression type ( default: none )
@property BOOL interleaveChannels;  // are the channels in the image interleaved? ( default: true )
@property NSInteger JPEGQuality;  // quality of produced image. Only valid for JPEG compressed TIFF documents ( 0 - 12 )
@property PhotoshopCCE325 layerCompression;  // should only be used when you are saving layers
@property BOOL saveAlphaChannels;  // save alpha channels
@property BOOL saveAnnotations;  // save annotations
@property BOOL saveImagePyramid;  // ( default: false )
@property BOOL saveLayers;  // save layers
@property BOOL saveSpotColors;  // save spot colors
@property BOOL transparency;


@end



/*
 * Export Formats Suite
 */

// used with options on the export command
@interface PhotoshopCCExportOptions : SBObject

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Settings related to exporting Illustrator paths
@interface PhotoshopCCIllustratorPathsExportOptions : PhotoshopCCExportOptions

@property (copy) NSString *pathName;  // name of path to export. Only valid if you are exporting a named path
@property PhotoshopCCE650 targetPath;  // which path to export ( default: document bounds )


@end

// Settings related to exporting Save For Web files
@interface PhotoshopCCSaveForWebExportOptions : PhotoshopCCExportOptions

@property double blur;  // apply blur to image to reduce artifacts ( default: 0.0 )
@property PhotoshopCCCR38 colorReduction;  // color reduction algorithm ( default: selective )
@property NSInteger colorsInPalette;  // number of colors in palette ( default: 256 )
@property PhotoshopCCE230 dither;  // type of dither ( default: diffusion )
@property NSInteger ditherAmount;  // amount of dither. Only valid for diffusion ( default: 100 )
@property BOOL interlaced;  // download in multiple passes, progressive ( default: false )
@property NSInteger lossy;  // controls amount of lossiness allowed ( default: 0 )
@property (copy) PhotoshopCCRGBColor *matte;  // defines colors to blend transparent pixels against
@property BOOL optimizedSize;  // creates smaller but less compatible files ( default: true )
@property BOOL pngEight;  // if the format is PNG how many bits, true = 8, false = 24 ( default: true )
@property NSInteger quality;  // quality of produced image ( default: 60 )
@property BOOL transparency;  // ( default: true )
@property NSInteger transparencyAmount;  // amount of transparency dither ( default: 100 )
@property PhotoshopCCE230 transparencyDither;  // transparency dither algorithm ( default: none )
@property PhotoshopCCSvFm webFormat;  // File format to use.  Note: Save For Web only supports Compuserve GIF, JPEG, PNG-8, PNG-24, and BMP formats. ( default: CompuServe GIF )
@property NSInteger webSnap;  // snaps close colors to web palette based on tolerance ( default: 0 )
@property BOOL withProfile;  // include an ICC profile based on Photoshop color compensation ( default: false )


@end



/*
 * Filter Suite
 */

// options used with the filter method
@interface PhotoshopCCFilterOptions : SBObject

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// apply the add noise filter
@interface PhotoshopCCAddNoise : PhotoshopCCFilterOptions

@property double amount;
@property PhotoshopCCE745 distribution;
@property BOOL monochromatic;


@end

// apply the average filter
@interface PhotoshopCCAverage : PhotoshopCCFilterOptions


@end

// apply the blur filter
@interface PhotoshopCCBlur : PhotoshopCCFilterOptions


@end

// apply the blur more filter
@interface PhotoshopCCBlurMore : PhotoshopCCFilterOptions


@end

// apply the clouds filter
@interface PhotoshopCCClouds : PhotoshopCCFilterOptions


@end

// apply the custom filter
@interface PhotoshopCCCustomFilter : PhotoshopCCFilterOptions

@property (copy) NSArray *characteristics;  // filter characteristics (array of 25 values - Correspons to a left to right, top to bottom traversal of array presented in the Ui)
@property NSInteger scaling;
@property NSInteger offset;


@end

// apply the de-interlace filter
@interface PhotoshopCCDeinterlace : PhotoshopCCFilterOptions

@property PhotoshopCCE755 eliminate;
@property PhotoshopCCE760 createNewFieldsBy;


@end

// apply the despeckle filter
@interface PhotoshopCCDespeckle : PhotoshopCCFilterOptions


@end

// apply the difference clouds filter
@interface PhotoshopCCDifferenceClouds : PhotoshopCCFilterOptions


@end

// apply the diffuse glow filter
@interface PhotoshopCCDiffuseGlow : PhotoshopCCFilterOptions

@property NSInteger graininess;  // (range: 0 - 10)
@property NSInteger glowAmount;  // (range: 0 - 20)
@property NSInteger clearAmount;  // (range: 0 - 20)


@end

// apply the displace filter
@interface PhotoshopCCDisplaceFilter : PhotoshopCCFilterOptions

@property NSInteger horizontalScale;
@property NSInteger verticalScale;
@property PhotoshopCCE725 kind;
@property PhotoshopCCE715 undefinedAreas;
@property (copy) id displacementMapDefinition;


@end

// apply the dust and scratches filter
@interface PhotoshopCCDustAndScratches : PhotoshopCCFilterOptions

@property NSInteger radius;  // in pixels
@property NSInteger threshold;


@end

// apply the gaussian blur filter
@interface PhotoshopCCGaussianBlur : PhotoshopCCFilterOptions

@property double radius;  // in pixels


@end

// apply the glass filter
@interface PhotoshopCCGlassFilter : PhotoshopCCFilterOptions

@property NSInteger distortion;  // (range: 0 - 20)
@property NSInteger smoothness;  // (range: 1 - 15)
@property NSInteger scaling;  // (range: 50 - 200)
@property BOOL invertTexture;  // ( default: false ) ( default: false )
@property PhotoshopCCE690 textureKind;
@property (copy) id textureDefinition;


@end

// apply the high pass filter
@interface PhotoshopCCHighPass : PhotoshopCCFilterOptions

@property double radius;  // in pixels


@end

// apply the lens blur filter
@interface PhotoshopCCLensBlur : PhotoshopCCFilterOptions

@property PhotoshopCCLB00 source;  // source for the depth map ( default: none ) ( default: none )
@property NSInteger focalDistance;  // blur focal distance for the depth map ( default: 0 ) ( default: 0 )
@property BOOL invertDepthMap;  // invert the depth map ( default: false ) ( default: false )
@property PhotoshopCCLB03 irisShape;  // shape of the iris ( default: hexagon ) ( default: hexagon )
@property NSInteger radius;  // radius of the iris ( default: 15 ) ( default: 15 )
@property NSInteger bladeCurvature;  // blade curvature of the iris ( default: 0 ) ( default: 0 )
@property NSInteger rotation;  // rotation of the iris ( default: 0 ) ( default: 0 )
@property NSInteger brightness;  // brightness for the specular highlights ( default: 0 ) ( default: 0 )
@property NSInteger threshold;  // threshold for the specular highlights ( default: 0 ) ( default: 0 )
@property NSInteger amount;  // amount of noise ( default: 0 ) ( default: 0 )
@property PhotoshopCCE745 distribution;  // distribution value for the noise ( default: uniform ) ( default: uniform )
@property BOOL monochromatic;  // is the noise monochromatic ( default: false ) ( default: false )


@end

// apply the lens flare filter
@interface PhotoshopCCLensFlare : PhotoshopCCFilterOptions

@property NSInteger brightness;  // (range: 10 - 300)
@property (copy) NSArray *flareCenter;  // position (unit value)
@property PhotoshopCCE750 lensType;


@end

// apply the maximum filter
@interface PhotoshopCCMaximumFilter : PhotoshopCCFilterOptions

@property double radius;  // in pixels


@end

// apply the median noise filter
@interface PhotoshopCCMedianNoise : PhotoshopCCFilterOptions

@property double radius;  // in pixels


@end

// apply the minimum filter
@interface PhotoshopCCMinimumFilter : PhotoshopCCFilterOptions

@property double radius;  // in pixels


@end

// apply the motion blur filter
@interface PhotoshopCCMotionBlur : PhotoshopCCFilterOptions

@property NSInteger angle;
@property double radius;  // in pixels


@end

// apply the NTSC colors filter
@interface PhotoshopCCNTSCColors : PhotoshopCCFilterOptions


@end

// apply the ocean ripple filter
@interface PhotoshopCCOceanRipple : PhotoshopCCFilterOptions

@property NSInteger rippleSize;  // (range: 1 - 15)
@property NSInteger rippleMagnitude;  // (range: 0 - 20)


@end

// apply the offset filter
@interface PhotoshopCCOffsetFilter : PhotoshopCCFilterOptions

@property double horizontalOffset;  // (unit value)
@property double verticalOffset;  // (unit value)
@property PhotoshopCCE718 undefinedAreas;


@end

// apply the pinch filter
@interface PhotoshopCCPinch : PhotoshopCCFilterOptions

@property NSInteger amount;  // (range: -100 - 100)


@end

// apply the polar coordinates filter
@interface PhotoshopCCPolarCoordinates : PhotoshopCCFilterOptions

@property PhotoshopCCE700 kind;


@end

// apply the radial blur filter
@interface PhotoshopCCRadialBlur : PhotoshopCCFilterOptions

@property NSInteger amount;  // from 0 to 100
@property PhotoshopCCE670 blurMethod;
@property PhotoshopCCE675 quality;


@end

// apply the ripple filter
@interface PhotoshopCCRipple : PhotoshopCCFilterOptions

@property NSInteger amount;  // (range: -999 - 999)
@property PhotoshopCCE710 rippleSize;


@end

// apply the sharpen filter
@interface PhotoshopCCSharpen : PhotoshopCCFilterOptions


@end

// apply the sharpen edges filter
@interface PhotoshopCCSharpenEdges : PhotoshopCCFilterOptions


@end

// apply the sharpen more filter
@interface PhotoshopCCSharpenMore : PhotoshopCCFilterOptions


@end

// apply the shear filter
@interface PhotoshopCCShear : PhotoshopCCFilterOptions

@property (copy) NSArray *curve;  // specification of shear curve. List of curve points
@property PhotoshopCCE715 undefinedAreas;


@end

// apply the smart blur filter
@interface PhotoshopCCSmartBlur : PhotoshopCCFilterOptions

@property double radius;  // radius (range: 0 - 1000)
@property double threshold;  // threshold (range: 0 - 1000)
@property PhotoshopCCE680 quality;
@property PhotoshopCCE685 mode;


@end

// apply the spherize filter
@interface PhotoshopCCSpherize : PhotoshopCCFilterOptions

@property NSInteger amount;  // (range: -100 - 100)
@property PhotoshopCCE720 mode;


@end

// apply the texture fill filter
@interface PhotoshopCCTextureFill : PhotoshopCCFilterOptions

@property (copy) id filePath;  // texture file. Must be a grayscale Photoshop file


@end

// apply the twirl filter
@interface PhotoshopCCTwirl : PhotoshopCCFilterOptions

@property NSInteger angle;  // (range: -999 - 999)


@end

// apply the unsharp mask filter
@interface PhotoshopCCUnsharpMask : PhotoshopCCFilterOptions

@property double amount;
@property double radius;  // in pixels
@property NSInteger threshold;  // threshold


@end

// apply the wave filter
@interface PhotoshopCCWaveFilter : PhotoshopCCFilterOptions

@property NSInteger numberOfGenerators;  // number of generators
@property NSInteger minimumWavelength;
@property NSInteger maximumWavelength;
@property NSInteger minimumAmplitude;
@property NSInteger maximumAmplitude;
@property NSInteger horizontalScale;
@property NSInteger verticalScale;
@property PhotoshopCCE730 waveType;
@property PhotoshopCCE715 undefinedAreas;
@property NSInteger randomSeed;


@end

// apply the zigzag filter
@interface PhotoshopCCZigzag : PhotoshopCCFilterOptions

@property NSInteger amount;  // (range: -100 - 100)
@property NSInteger ridges;
@property PhotoshopCCE740 style;


@end



/*
 * Adjustment Suite
 */

// options used with the adjust method
@interface PhotoshopCCAdjustmentOptions : SBObject

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// adjust contrast of the selected channels automatically
@interface PhotoshopCCAutomaticContrast : PhotoshopCCAdjustmentOptions


@end

// adjust levels of the selected channels using auto levels option
@interface PhotoshopCCAutomaticLevels : PhotoshopCCAdjustmentOptions


@end

// adjust brightness and constrast
@interface PhotoshopCCBrightnessAndContrast : PhotoshopCCAdjustmentOptions

@property NSInteger brightnessLevel;
@property NSInteger contrastLevel;


@end

@interface PhotoshopCCColorBalance : PhotoshopCCAdjustmentOptions

@property (copy) NSArray *shadows;  // list of adjustments for shadows. There must be 3 values in the list
@property (copy) NSArray *midtones;  // list of adjustments for midtones. There must be 3 values in the list
@property (copy) NSArray *highlights;  // list of adjustments for highlights. There must be 3 values in the list
@property BOOL preserveLuminosity;


@end

// adjust curves of the selected channels
@interface PhotoshopCCCurves : PhotoshopCCAdjustmentOptions

@property (copy) NSArray *curvePoints;  // list of curve points (number of points must be between 2 and 14)


@end

@interface PhotoshopCCDesaturate : PhotoshopCCAdjustmentOptions


@end

// equalize the levels
@interface PhotoshopCCEqualize : PhotoshopCCAdjustmentOptions


@end

// inverts the currently selected layer or channels
@interface PhotoshopCCInversion : PhotoshopCCAdjustmentOptions


@end

// adjust levels of the selected channels
@interface PhotoshopCCLevelsAdjustment : PhotoshopCCAdjustmentOptions

@property NSInteger inputRangeStart;
@property NSInteger inputRangeEnd;
@property double inputRangeGamma;
@property NSInteger outputRangeStart;
@property NSInteger outputRangeEnd;


@end

// only valid for RGB or CMYK documents
@interface PhotoshopCCMixChannels : PhotoshopCCAdjustmentOptions

@property (copy) NSArray *outputChannels;  // list of channel specifications. For each component channel that the document has, you must specify a list of adjustment values followed by a 'constant' value
@property BOOL monochromeMixing;  // use monochrome mixing? If this is true you can only specify one channel value ( default: false ) ( default: false )


@end

@interface PhotoshopCCPhotoFilter : PhotoshopCCAdjustmentOptions

@property (copy) PhotoshopCCColorValue *withContents;  // a color to use for the fill
@property NSInteger density;  // density of the filter effect as a percent ( default: 25 ) ( default: 25 )
@property BOOL preserveLuminosity;  // ( default: true ) ( default: true )


@end

@interface PhotoshopCCPosterize : PhotoshopCCAdjustmentOptions

@property NSInteger levels;


@end

@interface PhotoshopCCSelectiveColor : PhotoshopCCAdjustmentOptions

@property PhotoshopCCE890 selectionMethod;
@property (copy) NSArray *reds;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *yellows;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *greens;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *cyans;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *blues;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *magentas;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *whites;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *neutrals;  // Array of 4 values: cyan, magenta, yellow, black
@property (copy) NSArray *blacks;  // Array of 4 values: cyan, magenta, yellow, black


@end

@interface PhotoshopCCShadowHighlight : PhotoshopCCAdjustmentOptions

@property NSInteger shadowAmount;  // percentage from 0 to 100 ( default: 50 ) ( default: 50 )
@property NSInteger shadowWidth;  // percentage from 0 to 100 for tonal width (0 = narrow), (100 = broad) ( default: 50 ) ( default: 50 )
@property NSInteger shadowRadius;  // pixel amount from 0 to 2500 ( default: 30 ) ( default: 30 )
@property NSInteger highlightAmount;  // percentage from 0 to 100 ( default: 0 ) ( default: 0 )
@property NSInteger highlightWidth;  // percentage from 0 to 100 for tonal width (0 = narrow), (100 = broad) ( default: 50 ) ( default: 50 )
@property NSInteger highlightRadius;  // pixel amount from 0 to 2500 ( default: 30 ) ( default: 30 )
@property NSInteger colorCorrection;  // adjust the colors in the changed portion of the image (-100 to 100) ( default: 20 ) ( default: 20 )
@property NSInteger midtoneContrast;  // amount for the midtone contrast (-100 to 100) ( default: 0 ) ( default: 0 )
@property double blackClip;  // fractions of whites to be clipped ( default: 0.01 ) ( default: 0.01 )
@property double whiteClip;  // fractions of blacks to be clipped ( default: 0.01 ) ( default: 0.01 )


@end

@interface PhotoshopCCThresholdAdjustment : PhotoshopCCAdjustmentOptions

@property NSInteger level;


@end



/*
 * Color Suite
 */

// A color value
@interface PhotoshopCCColorValue : SBObject

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (PhotoshopCCColorValue *) convertColorTo:(PhotoshopCCE930)to;  // convert a object from one color model to another
- (BOOL) equalColorsWith:(PhotoshopCCColorValue *)with;  // are the colors visually equal?

@end

// A CMYK color specification
@interface PhotoshopCCCMYKColor : PhotoshopCCColorValue

@property double cyan;  // the cyan color value (between 0.0 and 100.0)
@property double magenta;  // the magenta color value (between 0.0 and 100.0)
@property double yellow;  // the yellow color value (between 0.0 and 100.0)
@property double black;  // the black color value (between 0.0 and 100.0)


@end

// A gray color specification
@interface PhotoshopCCGrayColor : PhotoshopCCColorValue

@property double grayValue;  // the gray value ( 0.0 - 100.0; default: 0.0 )


@end

// An HSB color specification
@interface PhotoshopCCHSBColor : PhotoshopCCColorValue

@property double hue;  // the hue value (between 0.0 and 360.0)
@property double saturation;  // the saturation value (between 0.0 and 100.0)
@property double brightness;  // the brightness value (between 0.0 and 100.0)


@end

// An Lab color specification
@interface PhotoshopCCLabColor : PhotoshopCCColorValue

@property double value_L;  // the L-value (between 0.0 and 100.0)
@property double value_a;  // the a-value (between -128.0 and 127.0)
@property double value_b;  // the b-value (between -128.0 and 127.0)


@end

// represents a missing color
@interface PhotoshopCCNoColor : PhotoshopCCColorValue


@end

// An RGB color specification
@interface PhotoshopCCRGBColor : PhotoshopCCColorValue

@property double red;  // the red color value ( 0.0 - 255.0; default: 255.0 )
@property double green;  // the green color value ( 0.0 - 255.0; default: 255.0 )
@property double blue;  // the blue color value ( 0.0 - 255.0; default: 255.0 )


@end

// A hexadecimal specification of an RGB color
@interface PhotoshopCCRGBHexColor : PhotoshopCCColorValue

@property (copy) NSString *hexValue;  // the hex representation of the color. (Example '10FF4B')


@end



/*
 * Path Suite
 */

// An artwork path item
@interface PhotoshopCCPathItem : SBObject

- (SBElementArray *) subPathItems;

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy, readonly) NSArray *entirePath;  // all the path item's sub paths
@property PhotoshopCCPT21 kind;
@property (copy) NSString *name;  // the name of the path item

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location
- (void) createSelectionFeatherAmount:(double)featherAmount antialiasing:(BOOL)antialiasing operation:(PhotoshopCCE630)operation;  // make a selection from this path
- (void) deselect;  // unselect this path item, no paths items are selected
- (void) fillPathWithContents:(id)withContents blendMode:(PhotoshopCCE925)blendMode opacity:(double)opacity preservingTransparency:(BOOL)preservingTransparency featherAmount:(double)featherAmount antialiasing:(BOOL)antialiasing wholePath:(BOOL)wholePath;  // fill the path with the following information
- (void) makeClippingPathFlatness:(double)flatness;  // make this path item the clipping path for this document
- (void) select;  // make this path item the active or selected path item
- (void) strokePathTool:(PhotoshopCCPT23)tool simulatePressure:(BOOL)simulatePressure;  // stroke the path with the following information

@end

// A point on a path
@interface PhotoshopCCPathPoint : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) NSArray *anchor;  // the position (coordinates) of the anchor point
@property (copy, readonly) SBObject *container;  // the object's container
@property (readonly) PhotoshopCCPT22 kind;  // the type of point: smooth/corner
@property (copy, readonly) NSArray *leftDirection;  // location of the left direction point (in position)
@property (copy, readonly) NSArray *rightDirection;  // location of the right direction point (out position)

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Path point information (returned by entire path dataClassProperty of path item class)
@interface PhotoshopCCPathPointInfo : SBObject

@property (copy) NSArray *anchor;  // the position of the anchor (in coordinates)
@property PhotoshopCCPT22 kind;  // the point type, smooth/corner
@property (copy) NSArray *leftDirection;  // location of the left direction point (in position)
@property (copy) NSArray *rightDirection;  // location of the right direction point (out position)

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// Sub path information (returned by entire path dataClassProperty of path item class)
@interface PhotoshopCCSubPathInfo : SBObject

@property BOOL closed;  // is this path closed?
@property (copy) NSArray *entireSubPath;  // all the sub path item's path points
@property PhotoshopCCPT45 operation;  // sub path operation on other sub paths

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

// An artwork sub path item
@interface PhotoshopCCSubPathItem : SBObject

- (SBElementArray *) pathPoints;

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (readonly) BOOL closed;  // is this path closed?
@property (copy, readonly) SBObject *container;  // the object's container
@property (copy, readonly) NSArray *entireSubPath;  // all the sub path item's path points
@property (readonly) PhotoshopCCPT45 operation;  // sub path operation on other sub paths

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end



/*
 * Notifier Suite
 */

// The parameters of the notifie
@interface PhotoshopCCNotifier : SBObject

@property (copy, readonly) NSNumber *bestType;  // the best type for the object's value
@property (copy, readonly) NSNumber *defaultType;  // the default type for the object's value
@property (readonly) NSInteger index;  // the index of this instance of the object
@property (copy) NSDictionary *properties;  // all of this object's properties returned in a single record
@property (copy, readonly) NSString *event;  // The id of the event, four characters or a unique string
@property (copy, readonly) NSString *eventClass;  // The class id the event applies to, four characters or a unique string. Allows you to distinguish between the same event applied to different classes.
@property (copy, readonly) id eventFile;  // The file to execute when the event occurs

- (void) delete;  // Remove an element from an object
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Duplicate one or more object(s)
- (BOOL) exists;  // Verify if an object exists
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location

@end

