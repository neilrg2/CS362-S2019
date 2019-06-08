import junit.framework.TestCase;

public class main extends TestCase {

    public static boolean unittest() {
        UrlValidator validator = new UrlValidator();

        assertTrue("Should be valid",
                validator.isValid("http://www.test.com"));

        assertFalse("Should not be valid",
                validator.isValid("htt://ww.test.com"));

        assertTrue("Should be valid",
                validator.isValid("http://www.test.org"));

        assertFalse("Should not be valid",
                validator.isValid("http://www.test"));

        return true;

    }

    public static boolean testValidatorSuite() {
        UrlValidatorTest urltest = new UrlValidatorTest("Test");
        urltest.testValidator202();
        urltest.testValidator204();
        urltest.testValidator235();
        urltest.testValidator248();
        urltest.testValidator276();
        urltest.testValidator288();
        urltest.testValidator290();
        urltest.testValidator309();
        urltest.testValidator339();
        urltest.testValidator339IDN();
        urltest.testValidator342();
        urltest.testValidator218();
        urltest.testValidator391FAILS();
        urltest.testValidator391OK();
        urltest.testValidator411();
        urltest.testValidator420();

        return true;
    }

    public static boolean testIsValidTest() {
        UrlValidatorTest urltest = new UrlValidatorTest("Test");
        urltest.testIsValid();

        return true;
    }

    public static void main(String []args) {

        System.out.println("Unit Test:");
        System.out.println("Testing isValid & testIsValid functions:");

        System.out.println("Test: \'unittest\'");
        if (unittest())
            System.out.println("PASS");
        else
            System.out.println("FAIL");
        System.out.println();

        System.out.println("Test: \'testValidatorSuite\'");
        if (testValidatorSuite())
            System.out.println("PASS");
        else
            System.out.println("FAIL");

        System.out.println();
        System.out.println("Test: \'testIsValidTest\'");
        if (testIsValidTest())
            System.out.println("PASS");
        else
            System.out.println("FAIL");



    }
}
