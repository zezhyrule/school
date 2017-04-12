-- Convert positive Integers to a list of digits.
toDigits	:: Integer -> [Integer]
toDigits n
  | n < 1	  = []
  | otherwise = toDigits (quot n 10) ++ [mod n 10]

-- Convert positive Integers to a list of digits and reverse the list.
toDigitsRev	:: Integer -> [Integer]
toDigitsRev n
  | n < 1	  = []
  | otherwise = reverse (toDigits n)

-- Double every other number beginning from the left.
doubleFromLeft :: [Integer] -> [Integer]
doubleFromLeft []		= []  -- Do nothing to the empty list  
doubleFromLeft (x:[])   = [x] -- Do nothing to lists with a single element
doubleFromLeft (x:y:zs) = x : (y * 2 : doubleFromLeft zs)

-- Double every other number beginning from the right.
doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther xs = reverse (doubleFromLeft (reverse xs))

-- Sum all the digits in a list of Integers together.
sumDigits :: [Integer] -> Integer
sumDigits [x]	= x  -- Return the element of a list with one element.
sumDigits (x:xs)
  | x < 10		= x + sumDigits xs
  | otherwise	= sumDigits (toDigits x) + sumDigits xs

-- Validate credit card number.
validate :: Integer -> Bool
validate n = mod (sumDigits (doubleEveryOther (toDigits n))) 10 == 0
