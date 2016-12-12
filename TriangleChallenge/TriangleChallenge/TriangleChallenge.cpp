// TriangleChallenge.cpp : Defines the entry point for the console application.
// Assignment for Tradeshift
// One function for determinating a Triangle 
// One function for automatic Testing
// Program can be used with no arguements or 2

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

// Triangle enum types
enum enTriangleType 
{
		ecTriangleTypeERROR_Input
	,	ecTriangleTypeERROR_Impossible
	,	ecTriangleTypeValid
	,	ecTriangleTypeEquilateral
	,	ecTriangleTypeIsosceles 
	,	ecTriangleTypeScalene
};

// Triangle type names
const char * ccTriangleType[] = { "Equilateral" , "Isosceles", "Scalene" }; 

// Function definitions
enTriangleType fnGetTriangleType( long nSideA, long nSideB, long nSideC );
void fnAutomaticTestTriangles( long nStartLength, long nEndlength );



enTriangleType fnGetTriangleType( long nSideA, long nSideB, long nSideC )
{
	// Check for errors in input arguements
	if(nSideA <= 0 || nSideB <= 0 || nSideC <= 0 )
	{
		// One of the sides is zero or less than zero return error
		return( ecTriangleTypeERROR_Input );
	}

	// Perform evaluation for Equilateral
	if( 
			( nSideA == nSideB ) &&
			( nSideC == nSideB ) 
	)
	{
		// All sides are identical no further check for valid Triangle
		return( ecTriangleTypeEquilateral );
	}

	// In order for any Triangle to be valid one side must always be shorter than the lenth of two others combined
	if( 
			!
			(
				( nSideA < ( nSideB + nSideC ) ) &&
				( nSideB < ( nSideA + nSideC ) ) &&
				( nSideC < ( nSideA + nSideB ) ) 
			)
	)
	{
		// The Triangle is impossible 
		return( ecTriangleTypeERROR_Impossible );
	}

	// Perform evaluation for Isosceles
	if( 
			nSideA == nSideB ||
			nSideA == nSideC ||
			nSideB == nSideC 
	)
	{
		// Two of the sides are identical
		return( ecTriangleTypeIsosceles );
	}
	
	// Otherwise the sides must be all different and the Triangle is Scalene	
	return( ecTriangleTypeScalene );
}
										  
void fnAutomaticTestTriangles( long nStartLength, long nEndlength )
{
	long nSideA, nSideB, nSideC;
	enTriangleType eTriangleType;

	printf(
		"\n" 
		"Autotesting Function fnGetTriangleType( %d..%d, %d..%d, %d..%d ) : "
		"\n" 
		,  nStartLength, nEndlength 
		,  nStartLength, nEndlength 
		,  nStartLength, nEndlength 
		);											 
								   		 				 

	// Test all Triangles possible with sides from nStartLength to nEndLength
	for( nSideA = nStartLength; nSideA <= nEndlength; nSideA ++ )
	for( nSideB = nStartLength; nSideB <= nEndlength; nSideB ++ )
	for( nSideC = nStartLength; nSideC <= nEndlength; nSideC ++ )
	{
		printf(
			"\n" 
			"Testing Triangle ( %2d, %2d, %2d ) : "
			, nSideA, nSideB, nSideC 
			);

		// Get the type of the Triangle
		eTriangleType = fnGetTriangleType( nSideA, nSideB, nSideC );

		if(	eTriangleType > ecTriangleTypeValid )
		{
			printf(
				"         "
				"The Geometry of the Triangle is %s."
				, ccTriangleType[ eTriangleType - ecTriangleTypeEquilateral ]
			);
			continue;
		}
		
		if(	eTriangleType == ecTriangleTypeERROR_Input )
		{
			printf(
				"Failure. Some of the Sides are Zero or less."
				);				
			continue;
		}
		
		if(	eTriangleType == ecTriangleTypeERROR_Impossible )
		{
			printf(
				"Failure. One Side is equal to or greater than the Others combined."
				);				
		}
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	// Assignment for Tradeshift
	// test by calling fnAutomaticTestTriangles( -1, 8 );
	// fnAutomaticTestTriangles( 3, 8 );
	
	//or use from dos prompt
	long x, y;

	if(argc != 3)
	{
		printf(
			"\nSyntax From Dos: TriangleChallenge [From] [To]\n"
			);
		char caX[10], caY[10];
		printf(
			"\nFrom: "
			);
		gets_s(caX, 10);
		printf(
			"\nTo: "
			);
		gets_s(caY, 10);
		x = atol((char *) caX);
		y = atol((char *) caY);
	}
	else
	{	
		x = atol((char *) argv[1]);
		y = atol((char *) argv[2]);
	}

	fnAutomaticTestTriangles( x, y );
	if(argc != 3) 
		getchar();


	return 0;
}

